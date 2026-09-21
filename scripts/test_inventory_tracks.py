import importlib.util
import json
from pathlib import Path
import shutil


SCRIPT = Path(__file__).with_name("inventory-tracks.py")
SPEC = importlib.util.spec_from_file_location("inventory_tracks", SCRIPT)
MODULE = importlib.util.module_from_spec(SPEC)
assert SPEC.loader is not None
SPEC.loader.exec_module(MODULE)


def _synthetic_root():
    root = SCRIPT.parents[1] / "local" / "research" / "002-track-viewer" / "_synthetic"
    if root.exists():
        shutil.rmtree(root)
    track = root / "GameData" / "Track"
    track.mkdir(parents=True)
    (track / "zeta.env").write_bytes(b"ENV\0synthetic")
    (track / "zeta.crp").write_bytes(b"CRP\0geometry-unknown")
    (track / "zeta_forward.key").write_bytes(b"KEY\0route")
    (track / "notes.txt").write_bytes(b"not a candidate family")
    return root


def test_synthetic_inventory_is_sorted_and_hashes_only_selected():
    root = _synthetic_root()
    try:
        result = MODULE.build_inventory(root, ("GameData/Track/zeta.crp",))
    finally:
        shutil.rmtree(root)

    assert result["candidate_count"] == 4
    assert [item["path"] for item in result["candidates"]] == [
        "GameData/Track/notes.txt",
        "GameData/Track/zeta.crp",
        "GameData/Track/zeta.env",
        "GameData/Track/zeta_forward.key",
    ]
    assert result["starter_set"]["files"][0]["sha256"] == (
        "9500942c6990f2abc2e4aeb3396bee7721b0e6b56b325dbdd61dd21ec4d0dded"
    )
    assert result["related_file_hypotheses"][0]["related_by_name"] == [
        "GameData/Track/zeta_forward.key"
    ]
    assert result["extraction_performed"] is False


def test_cli_output_is_json():
    root = _synthetic_root()
    output = root / "inventory.json"
    game = root / "game"
    track = game / "GameData" / "Track"
    try:
        track.mkdir(parents=True)
        (track / "tiny.crp").write_bytes(b"CRP")
        result = MODULE.build_inventory(game, ("GameData/Track/tiny.crp",))
        output.write_text(json.dumps(result), encoding="utf-8")
        assert json.loads(output.read_text(encoding="utf-8"))["candidate_count"] == 1
    finally:
        shutil.rmtree(root)
