"""Small regression checks for the PE indexer's export and RVA handling."""
from pathlib import Path
import struct
import importlib.util

_spec = importlib.util.spec_from_file_location("index_binaries", Path(__file__).with_name("index-binaries.py"))
_module = importlib.util.module_from_spec(_spec); _spec.loader.exec_module(_module)
parse_pe = _module.parse_pe


def put(buf, off, fmt, *values):
    struct.pack_into(fmt, buf, off, *values)


def synthetic_pe():
    b = bytearray(0x800)
    b[:2] = b"MZ"; put(b, 0x3c, "<I", 0x80); b[0x80:0x84] = b"PE\0\0"
    put(b, 0x84, "<HHIIIHH", 0x14c, 1, 0, 0, 0, 224, 0x103)
    opt = 0x98; put(b, opt, "<H", 0x10b); put(b, opt + 16, "<I", 0x1000)
    put(b, opt + 28, "<I", 0x400000); put(b, opt + 92, "<I", 16)
    put(b, opt + 96, "<II", 0x1100, 0x100)
    sec = opt + 224; b[sec:sec + 8] = b".text\0\0\0"
    put(b, sec + 8, "<I", 0x400); put(b, sec + 12, "<I", 0x1000)
    put(b, sec + 16, "<I", 0x400); put(b, sec + 20, "<I", 0x400); put(b, sec + 36, "<I", 0x60000020)
    # IMAGE_EXPORT_DIRECTORY: two functions, one named, proving names != funcs.
    e = 0x400 + 0x100
    put(b, e, "<IIHHIIIIIII", 0, 0, 0, 0, 0x1180, 1, 2, 1, 0x1140, 0x1150, 0x1160)
    put(b, 0x400 + 0x140, "<II", 0x1200, 0x1300)
    put(b, 0x400 + 0x150, "<I", 0x1170); put(b, 0x400 + 0x160, "<H", 0)
    b[0x400 + 0x170:0x400 + 0x174] = b"Foo\0"
    return b


def main():
    p = Path("local/derived/binary-index/synthetic-test.dat")
    p.write_bytes(synthetic_pe())
    try:
        _, summary, _, _, strings, _, _ = parse_pe(p)
        assert len(summary["exports"]) == 2
        assert summary["exports"][0]["name"] == "Foo"
        assert summary["exports"][1]["name"] is None
        assert summary["exports"][0]["rva"] == "0x1200"
    finally:
        p.unlink(missing_ok=True)
    print("index-binaries synthetic export test passed")


if __name__ == "__main__": main()
