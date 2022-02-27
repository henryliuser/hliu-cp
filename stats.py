import sys, os
from pathlib import Path
from collections import defaultdict
dir = "/".join(sys.argv[0].split('/')[:-1])
p = Path(dir)

ALL = False
counts = defaultdict(int)
ignore = ["/atcoder/L0", "/codeforces/L0", "/leetcode/easy", "other"]
yesext = [".cpp", ".py", ".hs", ".ml"]
bad = [".tle.", ".wa."]

def dfs(pt):
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

dfs(p)

for k, v in counts.items():
    print(f"{k:5}{v}")

print(f"\ntotal: {sum(counts.values())}")
