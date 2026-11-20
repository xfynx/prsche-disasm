"""Read raw bytes at a VA from the immutable original PE (no relocation).

Helper for Run705 scope evidence. Image base 0x400000; section headers map RVA
to raw file offset. Bytes beyond a section's SizeOfRawData are loader zero-fill.
"""
import hashlib
import struct
import sys

PE = r"F:\claude\porsche disasm\local\game\Porsche.exe"
IMAGE_BASE = 0x400000


def sections(data):
    pe_off = struct.unpack_from("<I", data, 0x3c)[0]
    assert data[pe_off:pe_off + 4] == b"PE\0\0"
    coff = pe_off + 4
    nsec = struct.unpack_from("<H", data, coff + 2)[0]
    opt_size = struct.unpack_from("<H", data, coff + 16)[0]
    opt = coff + 20
    sec = opt + opt_size
    out = []
    for i in range(nsec):
        o = sec + 40 * i
        name = data[o:o + 8].rstrip(b"\0").decode("ascii", "replace")
        vsize, vaddr, rsize, raddr = struct.unpack_from("<IIII", data, o + 8)
        out.append((name, vaddr, vsize, raddr, rsize))
    return out


def read_va(data, secs, va, n):
    rva = va - IMAGE_BASE
    for name, vaddr, vsize, raddr, rsize in secs:
        if vaddr <= rva < vaddr + max(vsize, rsize):
            off_in_sec = rva - vaddr
            if off_in_sec < rsize:
                avail = min(n, rsize - off_in_sec)
                raw = data[raddr + off_in_sec:raddr + off_in_sec + avail]
                if len(raw) < n:
                    raw = raw + b"\0" * (n - len(raw))  # loader zero-fill tail
                return name, raw, False
            return name, b"\0" * n, True  # loader zero-fill (.bss portion)
    raise ValueError("VA %08x not in any section" % va)


def main():
    data = open(PE, "rb").read()
    secs = sections(data)
    print("sha256", hashlib.sha256(data).hexdigest())
    for spec in sys.argv[1:]:
        va_s, n_s = spec.split(":")
        va, n = int(va_s, 16), int(n_s, 0)
        name, raw, zero = read_va(data, secs, va, n)
        print("%s bytes=%d section=%s zerofill=%s sha256=%s" % (
            va_s, n, name, zero, hashlib.sha256(raw).hexdigest()))
        print("   " + raw.hex())


if __name__ == "__main__":
    main()
