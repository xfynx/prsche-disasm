"""SHA-guarded supplementary function index for callbacks missed by Ghidra."""
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
INDEX=ROOT/'research/binary-index/manual-functions.jsonl'

def records(sha=None):
    rows=[json.loads(l) for l in INDEX.read_text().splitlines()] if INDEX.exists() else []
    seen=set()
    for row in rows:
        key=(row['sha256'],row['entry_va'])
        if key in seen:raise RuntimeError(f'Duplicate manual function {key}')
        seen.add(key)
        data=(ROOT/'local/game'/row['path']).read_bytes()
        if hashlib.sha256(data).hexdigest()!=row['sha256']:raise RuntimeError('Manual index original SHA differs')
        body=data[row['file_offset']:row['file_offset']+row['body_bytes']]
        if hashlib.sha256(body).hexdigest()!=row['body_sha256']:raise RuntimeError('Manual index instruction bytes differ')
        start,end=map(lambda x:int(x,16),row['ranges'][0])
        if start!=int(row['entry_va'],16) or end-start+1!=row['body_bytes'] or body[-1]!=0xc3:
            raise RuntimeError('Invalid manual function range/RET')
    return [row for row in rows if sha is None or row['sha256']==sha]

if __name__=='__main__':print(json.dumps({'verified_manual_functions':len(records())}))
