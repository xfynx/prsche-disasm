"""Create a read-only inventory of candidate track resources.

The inventory reads directory metadata and a short prefix from each file. It
hashes only the explicitly selected starter set; it never extracts archives or
loads the game executable.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path


DEFAULT_SELECTED = (
    "GameData/Track/skidpad.crp",
    "GameData/Track/skidpad.env",
    "GameData/Track/skidpad.edg",
    "GameData/Track/skidpad.fsh",
    "GameData/Track/skidpad.jnc",
    "GameData/Track/skidpad.map",
    "GameData/Track/canyon.crp",
    "GameData/Track/canyon.env",
    "GameData/Track/canyon.edg",
    "GameData/Track/canyon.jnc",
    "GameData/Track/canyon.map",
    "GameData/Track/canyon_fstart.scn",
)
PREFIX_BYTES = 32


def _sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for block in iter(lambda: handle.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def _signature(path: Path) -> dict[str, str]:
    prefix = path.read_bytes()[:PREFIX_BYTES]
    printable = "".join(chr(byte) if 32 <= byte < 127 else "." for byte in prefix)
    return {"hex": prefix.hex(), "ascii": printable}


def _relative(path: Path, root: Path) -> str:
    return path.relative_to(root).as_posix()


def _track_files(game_root: Path) -> list[Path]:
    track_dir = game_root / "GameData" / "Track"
    if not track_dir.is_dir():
        raise FileNotFoundError(f"track directory not found: {track_dir}")
    return sorted((item for item in track_dir.iterdir() if item.is_file()),
                  key=lambda item: _relative(item, game_root).casefold())


def _related_hypotheses(files: list[Path], game_root: Path) -> list[dict[str, object]]:
    """Group by naming convention only; these are not proven dependencies."""
    groups: dict[str, list[Path]] = {}
    for item in files:
        suffix = item.suffix.casefold()
        if suffix in {".crp", ".env", ".edg", ".fsh", ".jnc", ".map", ".dtx"}:
            groups.setdefault(item.stem.casefold(), []).append(item)

    hypotheses = []
    for stem in sorted(groups):
        family = groups[stem]
        prefix_matches = sorted(
            item for item in files
            if item.name.casefold().startswith(stem + "_")
            and item not in family
        )
        if not prefix_matches:
            continue
        hypotheses.append({
            "anchor": _relative(sorted(family, key=lambda p: p.name.casefold())[0], game_root),
            "related_by_name": [_relative(item, game_root) for item in prefix_matches],
            "basis": "shared lowercase basename prefix only; dependency and geometry role unverified",
        })
    return hypotheses


def build_inventory(game_root: Path, selected: tuple[str, ...] = DEFAULT_SELECTED) -> dict[str, object]:
    game_root = game_root.resolve()
    files = _track_files(game_root)
    file_records = []
    for path in files:
        stat = path.stat()
        file_records.append({
            "path": _relative(path, game_root),
            "size": stat.st_size,
            "suffix": path.suffix.lower(),
            "prefix_signature": _signature(path),
        })

    selected_records = []
    for relative in selected:
        path = (game_root / Path(relative)).resolve()
        if game_root not in path.parents:
            raise ValueError(f"selected path escapes game root: {relative}")
        if not path.is_file():
            raise FileNotFoundError(f"selected resource not found: {relative}")
        selected_records.append({
            "path": _relative(path, game_root),
            "size": path.stat().st_size,
            "sha256": _sha256(path),
        })

    return {
        "schema": "track-inventory-v1",
        "source": "local/game",
        "read_only": True,
        "extraction_performed": False,
        "prefix_bytes": PREFIX_BYTES,
        "candidate_count": len(file_records),
        "candidates": file_records,
        "related_file_hypotheses": _related_hypotheses(files, game_root),
        "starter_set": {
            "selection_basis": "small naming-group sample for follow-up inspection; not a geometry claim",
            "files": selected_records,
        },
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--game-root", type=Path, default=None,
                        help="game root containing GameData/Track (default: repo/local/game)")
    parser.add_argument("--output", type=Path, default=None,
                        help="JSON report (default: local/research/002-track-viewer/inventory.json)")
    parser.add_argument("--select", action="append", dest="selected",
                        help="relative resource to hash; repeatable (default: starter set)")
    args = parser.parse_args()
    repo = Path(__file__).resolve().parents[1]
    game_root = args.game_root or repo / "local" / "game"
    output = args.output or repo / "local" / "research" / "002-track-viewer" / "inventory.json"
    selected = tuple(args.selected) if args.selected else DEFAULT_SELECTED
    inventory = build_inventory(game_root, selected)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(inventory, indent=2, ensure_ascii=True) + "\n", encoding="utf-8")
    print(f"wrote {output} ({inventory['candidate_count']} candidates; "
          f"{len(inventory['starter_set']['files'])} hashes)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
