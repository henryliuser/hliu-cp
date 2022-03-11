import sys, os
from pathlib import Path
from collections import defaultdict
dir = "/".join(sys.argv[0].split('/')[:-1])
p = Path(dir)

ALL = True
lineCount = 0
counts = defaultdict(int)
ignore = ["/atcoder/L0", "/codeforces/L0", "/leetcode/easy", "other"]
yesext = [".cpp", ".py", ".hs", ".ml"]
bad = [".tle.", ".wa."]

def _gen(rd):
    b = rd(1024*1024)
    while b:
        yield b
        b = rd(1024*1024)

def dfs(pt):
    global lineCount
    for x in pt.iterdir():
        s = str(x)
        sl = s.lower()
        if x.is_dir():
            if not ALL and any(s.endswith(ig) for ig in ignore): continue
            dfs(x)
            continue
        if not any(s.endswith(ex) for ex in yesext): continue
        if any(sl.find(b) != -1 for b in bad): continue
        name, ext = os.path.splitext(os.path.basename(s))
        if not ext: continue
        counts[ext] += 1
        with x.open('rb') as f:
            cg = _gen(f.raw.read)
            cnt = sum(b.count(b'\n') for b in cg)

        lineCount += cnt

dfs(p)

for k, v in counts.items():
    print(f"{k:5}{v}")

print(f"\ntotal files: {sum(counts.values())}")
print(f"total lines: {lineCount}")
