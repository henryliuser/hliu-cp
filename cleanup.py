import sys, os
from pathlib import Path
dir = "/".join(sys.argv[0].split('/')[:-1])
p = Path(dir)

def dfs(pt):
    for x in pt.iterdir():
        s = str(x)
        if x.is_dir():
            dfs(x)
            continue
        name, ext = os.path.splitext(s)
        if not ext: os.remove(s)
