import struct
from pathlib import Path

prt_data = Path("local/game/FEData/Data/nfs5.prt").read_bytes()
print(f"Total size: {len(prt_data)}")

# Let's search for repeated patterns or record size
# Let's find all car model name strings or part category strings
# "356", "356A", "356B", "911", etc.
# Let's check record size: is it 120 bytes, 160 bytes, 240 bytes?
for sz in [96, 120, 128, 144, 160, 180, 200, 240, 256, 320, 360, 480]:
    if len(prt_data) % sz == 0:
        print(f"Possible record size divisor: {sz}, count = {len(prt_data) // sz}")

# Let's inspect the offsets of "Engine"
import re
engine_offsets = [m.start() for m in re.finditer(b'Engine\x00', prt_data)]
print(f"Engine occurrences: {len(engine_offsets)}")
if len(engine_offsets) > 1:
    diffs = [engine_offsets[i+1] - engine_offsets[i] for i in range(min(10, len(engine_offsets)-1))]
    print("Diffs between 'Engine':", diffs)

# Let's print out slices around the first few records
for i in range(min(5, len(engine_offsets))):
    off = engine_offsets[i]
    # Look 40 bytes before to 80 bytes after
    start = max(0, off - 40)
    chunk = prt_data[start : off + 80]
    print(f"\n--- Occurrence {i} at offset 0x{off:x} ({off}) ---")
    print("Hex:", chunk.hex(' '))
    # Look for strings in this chunk
    strs = [m.group(0).decode('ascii', errors='ignore') for m in re.finditer(b'[A-Za-z0-9_-]{2,}', chunk)]
    print("Strings:", strs)

