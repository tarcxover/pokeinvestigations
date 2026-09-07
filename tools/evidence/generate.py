#!/usr/bin/env -S uv run --script

# /// script
# dependencies = ["pyyaml"]
# ///
# pyright: basic

import re
from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path
from socket import if_indextoname
from textwrap import dedent

import yaml

type Macro = list[str]
type Deductions = defaultdict[str, list[list[str]]]
type Suspects = dict[str, list[str]]


@dataclass
class Evidence:
    id: str
    icon: str
    name: str
    recipes: list[list[str]]
    description: str
    details: str
    score: int
    suspects: list[str]
    question: list[str]

@dataclass(frozen=True)
class Question:
    id: str
    text: str


def find_project_root(start: Path) -> Path:
    path = next(
        (p for p in [start, *start.parents] if (p / "Makefile").is_file()),
        None,
    )
    if path is None:
        raise FileNotFoundError("Could not find project root (Makefile)")
    return path


def emit_macro(lines: list[str]) -> None:
    print(" \\\n".join(lines))


def emit_macro_line(line: str = "", suffix: str = "") -> None:
    print(f"{line}{suffix}\\")


def emit_compound_string(
    out: Macro,
    text: str,
    indent: str = "",
    suffix: str = "",
) -> None:
    lines = text.rstrip("\n").splitlines()

    if len(lines) == 1:
        out.append(f'{indent}COMPOUND_STRING("{lines[0]}"){suffix}')
        return

    out.append(f"{indent}COMPOUND_STRING(")

    for i, line in enumerate(lines):
        newline = r"\n" if i != len(lines) - 1 else ""
        out.append(f'{indent}    "{line}{newline}"')

    out.append(f"{indent}){suffix}")


def emit_generated_warning(source: Path) -> None:
    print(
        dedent(f"""\
        /////////////////////////////////////////////////////////////////////////////////////////
        // DO NOT MODIFY THIS FILE! It is auto-generated from {source}
        /////////////////////////////////////////////////////////////////////////////////////////
        """)
    )


def open_header_guard() -> None:
    print(
        dedent("""\
            #ifndef CONSTANTS_EVIDENCE_MACROS_H
            #define CONSTANTS_EVIDENCE_MACROS_H
        """)
    )


def emit_deduction_table(evidence: list[Evidence]) -> None:

    def collect_deductions(evidence: list[Evidence]) -> Deductions:
        order = {e.id: i for i, e in enumerate(evidence)}
        deductions: Deductions = defaultdict(list)
        for e in evidence:
            for r in e.recipes:
                res = sorted(r, key=order.__getitem__)
                if res not in deductions[e.id]:
                    deductions[e.id].append(res)
        return deductions

    def build_dedction_lnes(out: list[str], deductions: Deductions) -> None:
        for c, pp in deductions.items():
            for p in pp:
                line = ", ".join([c, *p])
                out.append(f"F({line})")

    deductions = collect_deductions(evidence)

    lines = ["#define FOREACH_DEDUCTION(F)"]
    build_dedction_lnes(lines, deductions)
    emit_macro(lines)


# Source - https://stackoverflow.com/a/952952
# Posted by Alex Martelli, modified by community. See post 'Timeline' for change history
# Retrieved 2026-08-20, License - CC BY-SA 4.0
def flatten(xss):
    return [x for xs in xss for x in xs]

def collect_suspects(evidence: list[Evidence]) -> Suspects:
    suspects = {}
    for e in evidence:
        if not e.suspects:
            continue
        suspects[e.id] = [s.upper() for s in sorted(e.suspects)]
    return suspects

def emit_suspect_table(evidence: list[Evidence]) -> None:

    def build_suspect_lines(out: list[str], suspects: Suspects) -> None:
        for e, s in suspects.items():
            line = ", ".join([e, *s])
            out.append(f"F({line})")

    suspects = collect_suspects(evidence)
    lines = ["#define FOREACH_EVIDENCE_SUSPECT(F)"]
    build_suspect_lines(lines, suspects)
    emit_macro(lines)

def emit_suspect_list(evidence: list[Evidence]) -> None:
    suspects = collect_suspects(evidence)
    suspect_list = flatten(suspects.values())
    suspect_list = sorted(set(suspect_list), key=lambda s: (s.lower() == "count", s))

    lines = ["#define FOREACH_SUSPECT(F)"]
    for s in suspect_list:
        lines.append(f"F({s.upper()})")

    emit_macro(lines)



def close_header_guard() -> None:
    print(dedent("\n#endif // CONSTANTS_EVIDENCE_MACROS_H"))

def get_evd_tag(evd: Evidence) -> str:
    name: str = evd.name
    tag: str = ''.join(name.split())
    sanitized_tag: str =  re.sub(r'[^a-zA-Z0-9]', '', tag)
    return sanitized_tag

def emit_evidence(out: Macro, evd: Evidence) -> None:
    out.append(f"F({evd.id},")
    emit_compound_string(out, evd.name, suffix=",")
    emit_compound_string(out, evd.description, suffix=",")
    emit_compound_string(out, evd.details, suffix=",")
    out.append(f"{evd.icon},")

    suspects = [s.upper() for s in evd.suspects]
    out.append(f"({",".join(suspects)}),")

    question = [q.upper() for q in evd.question]
    out.append(f"({",".join(question)}),")

    out.append(f"({evd.score}),")

    tag = get_evd_tag(evd)
    out.append(f"{tag})")

def emit_question_text(out: Macro, ques: Question) -> None:
    out.append(f"F({ques.id},")
    emit_compound_string(out, ques.text, suffix=")")


def build_evidence_list(data) -> list[Evidence]:
    res: list[Evidence] = [
        Evidence(
            id=item["id"],
            icon=item["icon"],
            name=item["name"],
            description=item["description"],
            details=item["details"],
            recipes=item.get("recipes") or [],
            score=item.get("score") or 0,
            suspects=item.get("suspects") or ["Count"],
            question=item.get("question") or ["None"],
        )
        for item in data["evidence"]
    ]
    return res

def build_question_map(data) -> list[Question]:
    res: list[Question] = [
        Question(
            id=item["id"],
            text=item["text"]
        )
        for item in data["questions"]
    ]
    return res

def calculate_score(evd: list[Evidence]):

    def get_evd_by_id(id: str):
        return next(e for e in evd if e.id == id)

    def is_deduction(evd_item: Evidence):
        deductions_required: int = evd_item.recipes != []
        return int(deductions_required)

    def get_score_for_evidence(evd_item: Evidence):
        num_deductions = is_deduction(evd_item)

        if not num_deductions:
            return 2

        for r in sorted(set(flatten(evd_item.recipes))):
            num_deductions += is_deduction(get_evd_by_id(r))

        if num_deductions > 1:
            return 13
        if num_deductions > 0:
            return 5
        else:
            return 2

    for i, e in enumerate(evd):
        evd[i].score = get_score_for_evidence(e)

def main() -> None:
    script_dir = Path(__file__).resolve().parent
    root = find_project_root(script_dir)
    source = root / "src" / "data" / "evidence.yaml"
    rel = source.relative_to(root)

    with source.open() as f:
        data = yaml.safe_load(f)

    evidence = build_evidence_list(data)
    questions = build_question_map(data)

    open_header_guard()
    emit_generated_warning(rel)

    calculate_score(evidence)

    lines = ["#define FOREACH_EVIDENCE(F)"]
    for e in evidence:
        emit_evidence(lines, e)

    emit_macro(lines)

    print()
    emit_deduction_table(evidence)
    print()
    emit_suspect_table(evidence)
    print()
    emit_suspect_list(evidence)
    print()

    ques_lines = ["#define FOREACH_QUESTION(F)"]
    for q in questions:
        emit_question_text(ques_lines, q)
    emit_macro(ques_lines)


    close_header_guard()


if __name__ == "__main__":
    main()
