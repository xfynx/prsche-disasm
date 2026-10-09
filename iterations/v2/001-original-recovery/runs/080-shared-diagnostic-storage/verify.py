#!/usr/bin/env python3
"""Execute Run080's native storage-alias fixture and record source provenance."""
import argparse
import hashlib
import json
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[5]
RUN = Path(__file__).resolve().parent
ORIGINAL_SHA256 = "ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39"
SOURCES = [
    RUN / "CMakeLists.txt",
    RUN / "shared_diagnostic_storage_probe.cpp",
    ROOT / "iterations/v2/001-original-recovery/source/include/porsche/shared_runtime_globals.hpp",
    ROOT / "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/shared_runtime_globals.cpp",
]


def sha256(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--probe", required=True, type=Path)
    parser.add_argument("--report", type=Path, default=RUN / "verification.json")
    args = parser.parse_args()
    result = subprocess.run([str(args.probe.resolve())], check=True, capture_output=True, text=True)
    output = json.loads(result.stdout)
    expected = {"x86": True, "address_005deb1c": True,
                "address_005deb74_numeric_aliases": True, "address_005deb78_all": True,
                "null_source_preserved": True, "writes_visible": True}
    if output != expected:
        raise SystemExit(f"storage alias proof mismatch: {output}")
    report = {
        "schema": 1,
        "original": {"module": "Porsche.exe", "sha256": ORIGINAL_SHA256},
        "probe": str(args.probe.resolve()),
        "result": output,
        "source_sha256": {path.relative_to(ROOT).as_posix(): sha256(path) for path in SOURCES},
        "scope": "Proves canonical owner/reference identity and bidirectional writes for VA 005deb1c, 005deb74 and 005deb78 under MSVC Win32; does not claim full original runtime differential coverage.",
    }
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"passed": True, "report": str(args.report), "result": output}))


if __name__ == "__main__":
    main()
