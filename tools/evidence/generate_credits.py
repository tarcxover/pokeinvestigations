#!/usr/bin/env -S uv run --script

# /// script
# dependencies = ["pyyaml", "inflection"]
# ///
# pyright: basic

from dataclasses import dataclass
from textwrap import dedent

import inflection


@dataclass
class Credits:
    category: str
    contributors: list[str]


from pathlib import Path

import yaml


def find_project_root(start: Path) -> Path:
    path = next(
        (p for p in [start, *start.parents] if (p / "Makefile").is_file()),
        None,
    )
    if path is None:
        raise FileNotFoundError("Could not find project root (Makefile)")
    return path


def emit_credits_entry(string: str):
    print(f"CREDITS_ENTRY({string}),")


def emit_generated_warning(source: Path) -> None:
    print(
        dedent(f"""\
        /////////////////////////////////////////////////////////////////////////////////////////
        // DO NOT MODIFY THIS FILE! It is auto-generated from {source}
        /////////////////////////////////////////////////////////////////////////////////////////
        """)
    )


def main():
    script_dir = Path(__file__).resolve().parent
    root = find_project_root(script_dir)
    source = root / "src" / "data" / "credits.yaml"
    rel = source.relative_to(root)

    emit_generated_warning(rel)

    with source.open() as f:
        data = yaml.safe_load(f)

    credit_dict = data["credits"]

    print("const struct CreditEntry gCreditStrings[] = {")

    for key in credit_dict:
        emit_credits_entry('"' + inflection.titleize(key) + '", TRUE')
        for contributor in credit_dict[key]:
            emit_credits_entry('"' + contributor + '"')
    print("CREDIT_NULL,")
    print("};")


if __name__ == "__main__":
    main()
