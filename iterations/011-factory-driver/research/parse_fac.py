import struct

def main():
    with open('local/game/FEData/Data/nfs5.fac', 'rb') as f:
        data = f.read()

    rec_size = 240
    num_recs = len(data) // rec_size
    print(f"Total size: {len(data)}, records: {num_recs}")

    with open('iterations/011-factory-driver/research/factory-driver-evidence.md', 'w', encoding='utf-8') as out:
        out.write('# Factory Driver Missions Evidence (`nfs5.fac`)\n\n')
        out.write(f'Catalog: `FEData/Data/nfs5.fac` ({len(data)} bytes, 34 missions $\\times$ 240 bytes).\n\n')
        out.write('| # | Hex Offset | Raw Non-Zero Ints / Values | Extracted Strings |\n')
        out.write('|---|---|---|---|\n')

        for i in range(num_recs):
            rec = data[i * rec_size : (i + 1) * rec_size]
            ints = struct.unpack('<60I', rec)
            # Find strings in record
            strs = []
            cur = []
            for b in rec:
                if 32 <= b <= 126:
                    cur.append(chr(b))
                else:
                    if len(cur) >= 2:
                        strs.append(''.join(cur))
                    cur = []
            if len(cur) >= 2:
                strs.append(''.join(cur))

            nonzeros = [f"[{idx}]={val}" for idx, val in enumerate(ints[:16]) if val != 0]
            nz_str = ", ".join(nonzeros[:6])
            s_str = ", ".join(f'"{s}"' for s in strs)
            out.write(f'| {i + 1} | 0x{i * rec_size:04X} | `{nz_str}` | {s_str} |\n')

    print("Written factory-driver-evidence.md")

if __name__ == '__main__':
    main()
