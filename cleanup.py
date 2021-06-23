import sys, os
from pathlib import Path
dir = "/".join(sys.argv[0].split('/')[:-1])
p = Path(dir)

safeExt = {".py", ".cpp", ".txt"}
safeName = {".git", ".DS_Store"}

def dfs(pt):
    for x in pt.iterdir():
        s = str(x)
        if x.is_dir() and s[-4:] != ".git":
            dfs(x)
            continue
        name, ext = os.path.splitext(os.path.basename(s))
        if name in safeName or ext in safeExt: continue
        print(f"rm: {s}")
        try: os.remove(s)
        except: print("Failed ^^\n")

dfs(p)