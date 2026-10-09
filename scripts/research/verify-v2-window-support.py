"""Run084: differential proof for three small original window helpers."""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
RUN = ROOT / "iterations/v2/001-original-recovery/runs/084-window-support"
SHA = "ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39"
sys.path.insert(0, str(ROOT / "local/tools/python-unicorn"))
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ESP, UC_X86_REG_EIP
from v2_source_dependencies import source_hashes

STACK, EXIT = 0x03108000, 0x03200000
SEND_STUB, POST_STUB, LAST_ERROR_STUB = 0x03210000, 0x03210010, 0x03210020


def put(u, address, value):
    u.mem_write(address, struct.pack("<I", value & 0xffffffff))


def word(u, address):
    return struct.unpack("<I", u.mem_read(address, 4))[0]


def cases():
    result = []
    for hwnd in (0, 0x1234):
        for selector in (0, 1, 0x80000000):
            for send_result in (0, 1):
                for post_result in (0, 1):
                    for last_error in (0, 5):
                        result.append(("p", hwnd, 0x466, 0x11223344,
                                       0xaabbccdd, selector, send_result,
                                       post_result, last_error))
    # Exact `0053bcb0` ABI arguments: cdecl(arg0=0x466,arg1=arg2=arg3=0).
    for hwnd in (0, 0x1234):
        for post_result in (0, 1):
            for last_error in (0, 5):
                result.append(("p", hwnd, 0x466, 0, 0, 0, 0,
                               post_result, last_error))
    for running in (0, 1, 0xffffffff):
        for hwnd in (0, 0x1234, 0xffffffff):
            result.append(("a", running, hwnd))
    for value in (0, 1, 0x80000000, 0xffffffff):
        result.append(("g", value))
    return result


def original(module, data, case):
    u = Uc(UC_ARCH_X86, UC_MODE_32)
    u.mem_map(0x00400000, 0x00300000)
    for section in module["sections"]:
        size = section["raw_size"]
        if size:
            start = 0x00400000 + section["rva"]
            u.mem_write(start, data[section["raw_offset"]:section["raw_offset"] + size])
    u.mem_map(0x03100000, 0x00010000)
    u.mem_map(EXIT, 0x1000)
    u.mem_map(0x03210000, 0x1000)
    u.mem_write(EXIT, b"\xc3" * 0x1000)

    events = []
    put(u, 0x005b22fc, SEND_STUB)
    put(u, 0x005b227c, POST_STUB)
    put(u, 0x005b213c, LAST_ERROR_STUB)
    if case[0] == "p":
        _, hwnd, arg0, arg1, arg2, arg3, send_result, post_result, last_error = case
        put(u, 0x006b7bf8, hwnd)
        args = [arg0, arg1, arg2, arg3]
        entry = 0x0053a8e0
    elif case[0] == "a":
        _, running, hwnd = case
        put(u, 0x006b7c14, running)
        put(u, 0x006b7bf8, hwnd)
        args = []
        entry = 0x00565560
        send_result = post_result = last_error = 0
    else:
        _, opaque = case
        put(u, 0x006a64a0, opaque)
        args = []
        entry = 0x00573980
        send_result = post_result = last_error = 0

    def hook(machine, address, _size, _user):
        if address not in (SEND_STUB, POST_STUB, LAST_ERROR_STUB):
            return
        sp = machine.reg_read(UC_X86_REG_ESP)
        ret = word(machine, sp)
        if address in (SEND_STUB, POST_STUB):
            kind = 1 if address == SEND_STUB else 2
            args4 = tuple(word(machine, sp + 4 + 4 * i) for i in range(4))
            events.append((kind, *args4))
            value = send_result if address == SEND_STUB else post_result
            cleanup = 16
        else:
            events.append((3, 0, 0, 0, 0))
            value = last_error
            cleanup = 0
        machine.reg_write(UC_X86_REG_EAX, value)
        machine.reg_write(UC_X86_REG_ESP, sp + 4 + cleanup)
        machine.reg_write(UC_X86_REG_EIP, ret)

    u.hook_add(UC_HOOK_CODE, hook)
    stack_words = [EXIT, *args]
    for i, value in enumerate(stack_words):
        put(u, STACK + i * 4, value)
    u.reg_write(UC_X86_REG_ESP, STACK)
    u.emu_start(entry, EXIT, count=10000)
    hwnd_state = word(u, 0x006b7bf8)
    running_state = word(u, 0x006b7c14)
    opaque_state = word(u, 0x006a64a0)
    flat_events = [x for event in events for x in event]
    return (u.reg_read(UC_X86_REG_EAX), running_state, hwnd_state,
            opaque_state, len(events), *flat_events)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--probe", type=Path, default=ROOT / "local/builds/v2/001-original-recovery/bin/Release/window_support_probe.exe")
    parser.add_argument("--report", type=Path, default=RUN / "verification.json")
    args = parser.parse_args()
    modules = [json.loads(line) for line in
               (ROOT / "research/binary-index/static/binaries.jsonl").read_text(encoding="utf-8").splitlines()]
    module = next(item for item in modules if item["file"] == "Porsche.exe")
    data = (ROOT / "local/game" / module["path"]).read_bytes()
    if hashlib.sha256(data).hexdigest() != SHA:
        raise RuntimeError("original Porsche.exe SHA mismatch")
    inputs = cases()
    process = subprocess.run([str(args.probe.resolve())],
                             input="".join(" ".join(map(str, case)) + "\n" for case in inputs),
                             text=True, capture_output=True, check=True)
    lines = process.stdout.splitlines()
    if len(lines) != len(inputs):
        raise RuntimeError(f"probe produced {len(lines)} rows for {len(inputs)} cases")
    outputs = []
    for case, line in zip(inputs, lines):
        actual = tuple(int(value, 0) for value in line.split())
        expected = original(module, data, case)
        if actual != expected:
            raise RuntimeError(f"{case}: original={expected} native={actual}")
        outputs.append({"input": list(case), "output": actual})

    compiled = [
        "iterations/v2/001-original-recovery/source/recovered/Porsche.exe/window_support.cpp",
        "iterations/v2/001-original-recovery/source/recovered/window_support_probe.cpp",
    ]
    report = {
        "schema": 1,
        "sha256": SHA,
        "function_vas": ["0053a8e0","00565560","00573980"],
        "full_function_vas": ["0053a8e0","00565560","00573980"],
        "partial_function_vas": [],
        "original": {"module": "Porsche.exe", "sha256": SHA},
        "functions": ["0053a8e0", "00565560", "00573980"],
        "indexed_callers": {
            "0053a8e0": [{"function": "0053bcb0", "site": "0053bcef"}],
            "00565560": ["004ad9d5", "004dc638", "004e25af", "004e27da", "0053ba91"],
            "00573980": {
                "direct_calls": ["0053ba9a"],
                "function_address_store": {"function": "00565950", "site": "00565955", "destination": "006b4934"}
            }
        },
        "cases": len(inputs),
        "native_cpp_equal_original_x86": True,
        "boundaries": ["USER32 SendNotifyMessageA", "USER32 PostMessageA", "KERNEL32 GetLastError"],
        "position_remove_abi": "cdecl(arg0,arg1,arg2,arg3); arg3!=0 selects SendNotifyMessageA, otherwise PostMessageA; both receive (hwnd,arg0,arg2,arg1).",
        "global_006a64a0": "opaque DWORD; original getter returns unchanged value; no semantic claim",
        "source_sha256": source_hashes(compiled + ["scripts/research/verify-v2-window-support.py", "iterations/v2/001-original-recovery/runs/084-window-support/CMakeLists.txt", "iterations/v2/001-original-recovery/runs/084-window-support/README.md"], compiled_sources=compiled),
        "probe_sha256": hashlib.sha256(args.probe.read_bytes()).hexdigest(),
        "fixtures": outputs,
    }
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"cases": len(inputs), "native_cpp_equal_original_x86": True,
                      "report": str(args.report)}))


if __name__ == "__main__":
    main()
