"""Print recovery counters from tracked artifacts without rebuilding the game."""

import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
CORPUS = ROOT / "research/v2/binaries"
REGISTRY = ROOT / "iterations/v2/001-original-recovery/source/recovered/functions.json"


def document(path):
    return json.loads(path.read_bytes())


def main():
    modules = sorted(path.parent for path in CORPUS.glob("*/listing.json"))
    listings = [document(path / "listing.json") for path in modules]
    decompilations = [document(path / "decompilation.json") for path in modules]
    functions = sum(item["functions"] for item in listings)
    pseudo_c = sum(item["pseudo_c_functions"] for item in decompilations)
    gaps = sum(item["unclassified_executable_bytes"] for item in listings)
    print(f"Corpus ({len(modules)} modules): {pseudo_c:,}/{functions:,} pseudo-C, "
          f"{gaps:,} unclassified executable bytes.")

    game, = (path for path in modules if document(path / "listing.json")["module"] == "Porsche.exe")
    listing = document(game / "listing.json")
    with (game / "functions.jsonl").open(encoding="utf-8") as stream:
        indexed = {int(json.loads(line)["entry_va"], 16) for line in stream}
    records = [row for row in document(REGISTRY)["functions"] if row["sha256"] == listing["sha256"]]
    registered = {int(row["entry_va"], 16) for row in records}
    verified = {int(row["entry_va"], 16) for row in records if row["status"] in {
        "native-differential-verified", "emulated-differential-verified", "native-import-thunk-verified"
    }}
    partial = {int(row["entry_va"], 16) for row in records if row["status"].startswith("partial-")}
    partial_only = (indexed & partial) - verified
    print(f"Porsche.exe: {listing['unclassified_executable_bytes']:,} unclassified executable bytes. "
          f"{len(indexed & registered):,}/{len(indexed):,} indexed addresses registered, "
          f"{len(partial_only):,} partial-only, {len(indexed - registered):,} without a registry entry. "
          f"{len(registered - indexed):,} registered addresses outside the automatic index.")


if __name__ == "__main__":
    main()
