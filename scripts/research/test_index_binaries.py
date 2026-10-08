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
    b = bytearray(0x1000)
    b[:2] = b"MZ"; put(b, 0x3c, "<I", 0x80); b[0x80:0x84] = b"PE\0\0"
    put(b, 0x84, "<HHIIIHH", 0x14c, 1, 0, 0, 0, 224, 0x103)
    opt = 0x98; put(b, opt, "<H", 0x10b); put(b, opt + 16, "<I", 0x1000)
    put(b, opt + 28, "<I", 0x400000); put(b, opt + 92, "<I", 16)
    put(b, opt + 96, "<IIII", 0x1a00, 0x100, 0x1100, 0x100)
    sec = opt + 224; b[sec:sec + 8] = b".text\0\0\0"
    put(b, sec + 8, "<I", 0xc00); put(b, sec + 12, "<I", 0x1000)
    put(b, sec + 16, "<I", 0xc00); put(b, sec + 20, "<I", 0x400); put(b, sec + 36, "<I", 0x60000020)
    # IMAGE_IMPORT_DESCRIPTOR: lookup and IAT tables deliberately differ.
    put(b, 0x500, "<5I", 0x1200, 0, 0, 0x1300, 0x1240)
    put(b, 0x514, "<5I", 0, 0, 0, 0x1310, 0x1260)
    b[0x700:0x70a] = b"FIRST.dll\0"
    b[0x710:0x71b] = b"SECOND.dll\0"
    put(b, 0x600, "<II", 0x1500, 0x80000007)
    put(b, 0x640, "<II", 0, 0)  # IAT storage is separate from lookup.
    put(b, 0x660, "<I", 0x1510)
    b[0x900:0x906] = b"\0\0One\0"
    b[0x910:0x916] = b"\0\0Two\0"
    # IMAGE_EXPORT_DIRECTORY: two functions, one named, proving names != funcs.
    e = 0xe00
    put(b, e, "<IIHHIIIIIII", 0, 0, 0, 0, 0x1b00, 1, 2, 1, 0x1ac0, 0x1ad0, 0x1ae0)
    put(b, 0xec0, "<II", 0x1c00, 0x1d00)
    put(b, 0xed0, "<I", 0x1b70); put(b, 0xee0, "<H", 0)
    b[0xf70:0xf74] = b"Foo\0"
    return b


def main():
    p = Path("local/derived/binary-index/synthetic-test.dat")
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_bytes(synthetic_pe())
    try:
        _, summary, _, _, strings, _, _ = parse_pe(p)
        assert len(summary["exports"]) == 2
        assert summary["exports"][0]["name"] == "Foo"
        assert summary["exports"][1]["name"] is None
        assert summary["exports"][0]["rva"] == "0x1c00"
        _, _, _, _, _, _, imports = parse_pe(p)
        assert [(row["dll"], row["symbol"], row["iat_rva"]) for row in imports] == [
            ("FIRST.dll", "One", "0x1240"),
            ("FIRST.dll", "ordinal:7", "0x1244"),
            ("SECOND.dll", "Two", "0x1260"),
        ]
    finally:
        p.unlink(missing_ok=True)
    print("index-binaries synthetic export test passed")


if __name__ == "__main__": main()
