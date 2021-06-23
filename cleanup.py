import sys, os
from pathlib import Path
dir = "/".join(sys.argv[0].split('/')[:-1])
p = Path(dir)

safe = {".py", ".cpp", ".txt"}

def dfs(pt):
    for x in pt.iterdir():
        s = str(x)
        if x.is_dir() and s[-4:] != ".git":
            dfs(x)
            continue
        name, ext = os.path.splitext(s)
        if ext not in safe:
            print(f"rm: {s}")
            os.remove(s)

dfs(p)
