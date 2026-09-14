#!/usr/bin/env -S uv run --script

# /// script
# dependencies = ["pyyaml", "inflection"]
# ///
# pyright: basic

from ast import match_case
from dataclasses import dataclass
from enum import Enum
from textwrap import dedent

import inflection


class CreditType(Enum):
    CATEGORY = 0
    HEADER = 1
    ENTRY = 2


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


def emit_credits_entry(string: str, *args: str):
    macro_args: list[str] = [string] + list(args)
    print(f"CREDITS_ENTRY({','.join(macro_args)}),")


def emit_generated_warning(source: Path) -> None:
    print(
        dedent(f"""\
        /////////////////////////////////////////////////////////////////////////////////////////
        // DO NOT MODIFY THIS FILE! It is auto-generated from {source}
        /////////////////////////////////////////////////////////////////////////////////////////
        """)
    )


def quote_string(string: str) -> str:
    return '"' + string + '"'


def transform_entry_text(text: str, level: int):
    if text.startswith("$"):
        return quote_string(text[1:])
    match level:
        case 0:
            return quote_string(inflection.titleize(text).upper())
        case 1 | 2:
            return quote_string(inflection.titleize(text))
        case _:
            return quote_string(text)


def get_credit_type(level: int) -> str:
    credit_types = {0: "CREDIT_CATEGORY", 1: "CREDIT_HEADER", 2: "CREDIT_SUBHEADER"}
    return credit_types.get(level, "CREDIT_ENTRY")

def process_credit_dict(credits: dict, depth: int):
    for key, value in credits.items():
        emit_credits_entry(transform_entry_text(key, depth), get_credit_type(depth))
        if isinstance(value, dict):
            process_credit_dict(value, depth + 1)
        else:
            for contributor in value:
                emit_credits_entry(quote_string(contributor), "CREDIT_ENTRY")


def main():
    script_dir = Path(__file__).resolve().parent
    root = find_project_root(script_dir)
    source = root / "src" / "data" / "credits.yaml"
    rel = source.relative_to(root)

    emit_generated_warning(rel)

    with source.open() as f:
        data = yaml.safe_load(f)

    credit_dict = data["credits"]

    process_credit_dict(credit_dict, 0)
    print("CREDIT_NULL,")

if __name__ == "__main__":
    main()
