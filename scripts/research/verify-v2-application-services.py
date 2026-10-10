"""Compare the recovered startup audio setup body with original x86 bytes."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

from v2_source_dependencies import source_hashes

ROOT = Path(__file__).resolve().parents[2]
SHA = "ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39"
BASE, START, SIZE = 0x400000, 0x4A6840, 0x117
ARENA, ARENA_BYTES = 0x6573E8, 0x3E24
RECORDS = 0x6564A0
EXIT, STACK = 0x222F000, 0x2201000
BOUNDARIES = {
    0x531CA0: (3, 3), 0x4A66B0: (4, 0), 0x4AE100: (5, 3),
    0x4A8B80: (6, 0), 0x4AE2B0: (7, 0), 0x4AB4B0: (8, 0),
    0x565890: (9, 0), 0x531F90: (10, 1),
}


def cases():
    # first, second, mode 657c98, initial gate 657c94,
    # initialize result, allocator succeeds, measure result
    return [
        [0x40000, 0x8000, 3, 0, 0, 1, 7],  # mode 3, initialize failure
        [0x40000, 0x8000, 2, 0, 1, 1, 9],  # start path, positive config
        [0x40000, 0x8000, 2, 1, 1, 1, 11], # cleanup path, positive config
        [0, 0xDEADBEEF, 1, 1, 1, 1, 0],    # zero config, cleanup path
        [0xFFFFFFFF, 0x12345678, 1, 0, 1, 1, 1], # signed-negative config
        [7, 0x87654321, 3, 0x55, 1, 0, 0xFFFFFFFF], # mode overrides gate, null alloc
        [0, 0, 0, 0, 1, 1, 0x7FFFFFFF],   # start path, no configure call
    ]


def init_records():
    words = []
    for i in range(8):
        words.extend((0x1000 + i, 0x2000 + i, 0x3000 + i, 0x4000 + i))
    return words


def original(module, image, values):
    sys.path.insert(0, str(ROOT / "local/tools/python-unicorn"))
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
    from unicorn.x86_const import (
        UC_X86_REG_EAX, UC_X86_REG_EBX, UC_X86_REG_EIP,
        UC_X86_REG_ESP, UC_X86_REG_ESI,
    )
    uc = Uc(UC_ARCH_X86, UC_MODE_32)
    uc.mem_map(BASE, 0x300000)
    for section in module["sections"]:
        if section["raw_size"]:
            uc.mem_write(BASE + section["rva"], image[section["raw_offset"]:
                section["raw_offset"] + section["raw_size"]])
    uc.mem_map(0x2200000, 0x30000)

    def put(addr, value):
        uc.mem_write(addr, struct.pack("<I", value & 0xFFFFFFFF))

    def get(addr):
        return struct.unpack("<I", uc.mem_read(addr, 4))[0]

    first, second, mode, gate, init, alloc, measure = values
    arena = [0xABABABAB] * (ARENA_BYTES // 4)
    for va, value in ((0x657C94, gate), (0x657C98, mode), (0x657C9C, 0xCCCCCCCC)):
        arena[(va - ARENA) // 4] = value
    uc.mem_write(ARENA, struct.pack(f"<{len(arena)}I", *arena))
    uc.mem_write(RECORDS, struct.pack("<32I", *init_records()))
    put(0x655D34, 0x11111111)
    put(0x655D38, 0x22222222)
    uc.mem_write(0x655D3C, b"\x33")
    put(0x655D44, 0x44444444)
    put(0x5D1734, 0x55555555)
    put(STACK, EXIT)
    put(STACK + 4, first)
    put(STACK + 8, second)
    uc.reg_write(UC_X86_REG_ESP, STACK)
    uc.reg_write(UC_X86_REG_EBX, 0xB16B00B5)
    uc.reg_write(UC_X86_REG_ESI, 0x13572468)
    trace = []

    def hook(machine, address, _size, _user):
        if address == EXIT:
            machine.emu_stop()
            return
        item = BOUNDARIES.get(address)
        if item is None:
            return
        event_id, argc = item
        sp = machine.reg_read(UC_X86_REG_ESP)
        args = [get(sp + 4 + 4 * i) for i in range(argc)]
        trace.append([event_id, *(args + [0] * (4 - len(args)))])
        result = 0
        if address == 0x531CA0:
            result = 0x23000000 if alloc else 0
        elif address == 0x4A66B0:
            result = init & 0xFF
        elif address == 0x565890:
            result = measure
        machine.reg_write(UC_X86_REG_EAX, result & 0xFFFFFFFF)
        machine.reg_write(UC_X86_REG_ESP, sp + 4)
        machine.reg_write(UC_X86_REG_EIP, get(sp))

    uc.hook_add(UC_HOOK_CODE, hook)
    try:
        uc.emu_start(START, EXIT + 1, count=10000)
    except Exception as error:
        raise RuntimeError(f"original x86 fault at {uc.reg_read(UC_X86_REG_EIP):08x}; {trace}") from error
    if uc.reg_read(UC_X86_REG_EIP) != EXIT:
        raise AssertionError("original 004a6840 did not return")
    final_arena = list(struct.unpack(f"<{len(arena)}I", uc.mem_read(ARENA, ARENA_BYTES)))
    records = list(struct.unpack("<32I", uc.mem_read(RECORDS, 0x80)))
    outside = [get(0x655D34), get(0x655D38), uc.mem_read(0x655D3C, 1)[0],
               get(0x655D44), get(0x5D1734)]
    return {
        "trace": trace, "arena": final_arena, "records": [records[i:i + 4] for i in range(0, 32, 4)],
        "outside": outside,
        "entry_stack_restored": uc.reg_read(UC_X86_REG_ESP) == STACK + 4,
        "ebx_restored": uc.reg_read(UC_X86_REG_EBX) == 0xB16B00B5,
        "esi_restored": uc.reg_read(UC_X86_REG_ESI) == 0x13572468,
    }


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--probe", type=Path, default=ROOT / "local/builds/v2/application-services-128/bin/Release/application_services_probe.exe")
    parser.add_argument("--report-dir", type=Path, required=True)
    args = parser.parse_args()
    args.report_dir.mkdir(parents=True, exist_ok=True)
    module = next(x for x in map(json.loads, (ROOT / "research/binary-index/static/binaries.jsonl").read_text().splitlines()) if x["file"] == "Porsche.exe")
    image = (ROOT / "local/game" / module["path"]).read_bytes()
    if hashlib.sha256(image).hexdigest() != SHA:
        raise AssertionError("frozen executable hash mismatch")
    def raw(va, size):
        rva = va - BASE
        section = next(s for s in module['sections']
                       if s['rva'] <= rva and rva + size <= s['rva'] + s['raw_size'])
        offset = section['raw_offset'] + rva - section['rva']
        return image[offset:offset+size]
    functions = [json.loads(line) for line in
        (ROOT/'research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl').read_text().splitlines()]
    body_row = next(row for row in functions if row['entry_va'] == '004a6840')
    assert body_row['ranges'] == [['004a6840', '004a6956']]
    # Original caller stack words and direct IAT calls, independent of the
    # recovered adapter's own expectations.
    for va, expected in (
        (0x4b6a7b, '5368f86e5d00689c6e5d0053ff1570225b00'),
        (0x4b6aa0, '8b0d60b365005351ff1584205b00'),
        (0x4b6aff, '68008000006800000400e832fdfeff')):
        assert raw(va, len(bytes.fromhex(expected))) == bytes.fromhex(expected)
    imports = [json.loads(line) for line in
        (ROOT/'research/binary-index/static/imports.jsonl').read_text().splitlines()]
    for iat, symbol in (('0x1b2270', 'MessageBoxA'), ('0x1b2084', 'CreateDirectoryA')):
        assert any(row['path'] == 'Porsche.exe' and row['iat_rva'] == iat
                   and row['symbol'] == symbol for row in imports)
    for va, text in ((0x5d6e9c, b'Insufficient space in the swap file.  Please make additional space available and try again.\0'),
                     (0x5d6ef8, b'Memory full\0')):
        assert raw(va, len(text)) == text
    assert raw(0x5d1734, 4) == struct.pack('<I', 1)
    all_cases = cases()
    run = subprocess.run([str(args.probe)], input="".join(" ".join(map(str, c)) + "\n" for c in all_cases),
                         text=True, capture_output=True, check=True)
    actuals = [json.loads(line) for line in run.stdout.splitlines()]
    if len(actuals) != len(all_cases):
        raise AssertionError(f"native returned {len(actuals)} rows, expected {len(all_cases)}")
    summaries = []
    for index, (values, actual) in enumerate(zip(all_cases, actuals)):
        expected = original(module, image, values)
        if not all(expected[k] for k in ("entry_stack_restored", "ebx_restored", "esi_restored")):
            raise AssertionError(f"x86 ABI preservation mismatch case {index}: {expected}")
        for key in ("arena", "records", "outside"):
            if actual[key] != expected[key]:
                raise AssertionError(f"case {index} {key} mismatch: x86/native differ")
        if actual["trace"][2:] != expected["trace"]:
            raise AssertionError(f"case {index} call trace mismatch: x86={expected['trace']}; native={actual['trace'][2:]}")
        if actual["trace"][:2] != [[1, 0, 0, 0, 0], [2, 0x0065B360, 0, 0, 0]]:
            raise AssertionError(f"app_main direct API adapter call shape mismatch: {actual['trace'][:2]}")
        if actual["apis"] != ["Insufficient space in the swap file.  Please make additional space available and try again.", "Memory full", "install-root"]:
            raise AssertionError(f"source-proven MessageBoxA/CreateDirectoryA data mismatch: {actual['apis']}")
        summaries.append({"index": index, "first_signed": struct.unpack("<i", struct.pack("<I", values[0]))[0],
                          "mode": values[2], "gate": values[3], "audio_initialize": values[4],
                          "audio_calls": len(expected["trace"])})

    rva = START - BASE
    section = next(s for s in module["sections"] if s["rva"] <= rva < s["rva"] + s["raw_size"])
    offset = section["raw_offset"] + rva - section["rva"]
    function_hash = hashlib.sha256(image[offset:offset + SIZE]).hexdigest()
    source_paths = [
        "iterations/v2/001-original-recovery/source/include/porsche/application_services.hpp",
        "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_services.cpp",
        "iterations/v2/001-original-recovery/source/recovered/application_services_probe.cpp",
        "iterations/v2/001-original-recovery/source/platform/application_service_links.cpp",
        "scripts/research/verify-v2-application-services.py",
        "iterations/v2/001-original-recovery/runs/128-application-services/CMakeLists.txt",
        "iterations/v2/001-original-recovery/runs/128-application-services/README.md",
        "research/binary-index/static/binaries.jsonl",
        "research/binary-index/static/imports.jsonl",
        "research/v2/binaries/Porsche.exe-ddd748fdbe6d/functions.jsonl",
        "research/v2/binaries/Porsche.exe-ddd748fdbe6d/disassembly.asm",
    ]
    compiled = [
        ROOT / "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_services.cpp",
        ROOT / "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/application_state.cpp",
        ROOT / "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/install_paths_storage.cpp",
        ROOT / "iterations/v2/001-original-recovery/source/recovered/application_services_probe.cpp",
        ROOT / "iterations/v2/001-original-recovery/source/platform/application_service_links.cpp",
    ]
    report = {
        "schema": 1, "module": "Porsche.exe", "sha256": SHA, "module_sha256": SHA,
        "function_vas": ["004a6840"], "full_function_vas": ["004a6840"],
        "partial_function_vas": [], "cases": len(all_cases),
        "native_cpp_equal_original_x86": True,
        "comparison_boundary": "Complete 004a6840 control flow; complete 006573e8..0065b20b arena snapshot; exact 655d34/38/3c/44 and 8x16-byte 6564a0 records; 005d1734; allocator/audio-boundary trace and cdecl ABI preservation. App_main API adapters checked against source call arguments.",
        "caller_vas": ["004b6a50"],
        "global_vas": ["00657c94", "00657c98", "00657c9c", "00655d34", "00655d38", "00655d3c", "00655d44", "006564a0", "0065651f", "005d1734"],
        "original_functions": [{"va": "004a6840", "body_bytes": SIZE, "body_sha256": function_hash}],
        "cases_summary": summaries,
        "source_sha256": source_hashes([ROOT / p for p in source_paths], compiled_sources=compiled),
    }
    (args.report_dir / "verification.json").write_text(json.dumps(report, indent=2) + "\n", newline="\n")
    print(json.dumps({k: report[k] for k in ("sha256", "function_vas", "full_function_vas", "partial_function_vas", "cases", "native_cpp_equal_original_x86")}))


if __name__ == "__main__":
    main()
