import csv
import struct

def main():
    # 1. Load string table from festrings.csv
    strings = {}
    with open('local/game/FEData/Locale/festrings.csv', 'r', encoding='latin1', errors='replace') as f:
        reader = csv.reader(f)
        for row in reader:
            if not row:
                continue
            try:
                sid = int(row[0])
                eng = row[1] if len(row) > 1 else ""
                strings[sid] = eng
            except ValueError:
                pass

    print(f"Loaded {len(strings)} strings from festrings.csv")

    # 2. Load missions from nfs5.fac
    with open('local/game/FEData/Data/nfs5.fac', 'rb') as f:
        data = f.read()

    rec_size = 240
    num_recs = len(data) // rec_size

    with open('iterations/011-factory-driver/research/missions_catalog.md', 'w', encoding='utf-8') as out:
        out.write('# Factory Driver 34 Missions Full Specification\n\n')
        out.write('Extracted from `FEData/Data/nfs5.fac` and `FEData/Locale/festrings.csv`.\n\n')

        for i in range(num_recs):
            rec = data[i * rec_size : (i + 1) * rec_size]
            ints = struct.unpack('<60I', rec)
            base_str_id = ints[0]

            # Let's extract strings associated with base_str_id:
            # Usually:
            # base_str_id + 0: Mission Title
            # base_str_id + 1: Briefing / Goal text
            # base_str_id + 2: Instructions / Tips
            # base_str_id + 3: Pass message
            # base_str_id + 4: Fail message
            # etc.
            title = strings.get(base_str_id, f"Mission {i+1}")
            briefing = strings.get(base_str_id + 1, "")
            tip = strings.get(base_str_id + 2, "")
            pass_msg = strings.get(base_str_id + 3, "")
            fail_msg = strings.get(base_str_id + 4, "")

            # Mission code from raw bytes
            code = rec[16:24].split(b'\x00')[0].decode('latin1', 'replace')
            if not code:
                code = f"M{i+1:02d}"

            out.write(f'## Mission {i+1:02d} ({code}): {title}\n\n')
            out.write(f'- **Base String ID**: {base_str_id}\n')
            out.write(f'- **Tier / Level**: {ints[2]}\n')
            out.write(f'- **Briefing**: {briefing}\n')
            if tip:
                out.write(f'- **Tip**: {tip}\n')
            if pass_msg:
                out.write(f'- **Pass Feedback**: {pass_msg}\n')
            if fail_msg:
                out.write(f'- **Fail Feedback**: {fail_msg}\n')

            out.write(f'- **Raw Parameters**: ints[0..15] = {list(ints[:16])}\n\n')

    print("Written missions_catalog.md!")

if __name__ == '__main__':
    main()
