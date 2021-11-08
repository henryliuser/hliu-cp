import sys, os
from pathlib import Path
from collections import defaultdict
dir = "/".join(sys.argv[0].split('/')[:-1])
p = Path(dir)

counts = defaultdict(int)

def dfs(pt):
    for x in pt.iterdir():
        s = str(x)
        if s.endswith("other") or s.endswith(".git"): continue
        if x.is_dir():
            dfs(x)
            continue
        name, ext = os.path.splitext(os.path.basename(s))
        if not ext: continue
        counts[ext] += 1

dfs(p)

for k, v in counts.items():
    print(f"{k:5}{v}")
