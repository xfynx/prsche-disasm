"""Annotate kernel bodies with live ESP delta so [esp+N] resolves to frame cells.

Reads scope-evidence.json (read-only census) and writes stack-annotated listings.
"""
import json, re, sys
from pathlib import Path

RUN = Path(__file__).resolve().parent
d = json.loads((RUN / 'scope-evidence.json').read_bytes())
bodies = {b['va']: b for b in d['bodies']}


def annotate(va: str):
    ins = bodies[va]['instructions']
    esp = 0
    out = []
    for i in ins:
        asm = i['asm']
        mnem = asm.split()[0]
        # resolve [esp+X] / [esp - X] against current offset
        def repl(m):
            expr = m.group(1).replace(' ', '')
            # simple decimal/hex constants only
            mm = re.fullmatch(r'([+-])?(0x[0-9a-f]+|\d+)', expr)
            if not mm:
                return m.group(0)
            sign = -1 if mm.group(1) == '-' else 1
            v = int(mm.group(2), 16) if mm.group(2).startswith('0x') else int(mm.group(2))
            cell = esp + sign * v
            # cell measured from esp0 (frame base); args/return live above 0x224
            return f'[FRAME{cell:+#x}]'
        shown = re.sub(r'\[esp\s*([+-]\s*(?:0x[0-9a-f]+|\d+))\]', repl, asm)
        # annotate the *following* instruction with the esp after this one? No: annotate
        # this instruction with esp in effect at its own address (before its effect).
        out.append(f'{i["va"]} {asm:<48} ; esp={esp:+#x}   {shown}')
        if mnem == 'push':
            esp -= 4
        elif mnem == 'pop':
            esp += 4
        elif mnem == 'call':
            pass
        elif mnem == 'ret':
            pass
        elif mnem == 'sub' and asm.startswith('sub esp'):
            esp -= int(asm.split(',')[1].strip(), 0)
        elif mnem == 'add' and asm.startswith('add esp'):
            esp += int(asm.split(',')[1].strip(), 0)
    return '\n'.join(out)


if __name__ == '__main__':
    for va in sys.argv[1:] or ['0059a910']:
        print(f'===== {va} {bodies[va]["bytes"]}B sha256={bodies[va]["sha256"]}')
        print(annotate(va))
