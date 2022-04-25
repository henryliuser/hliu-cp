import sys, os
from pathlib import Path
dir = "/".join(sys.argv[0].split('/')[:-1])
p = Path(dir)

safeExt = {
    ".py", ".cpp", ".txt", ".md", ".hs",
    ".ml", ".code-snippets", ".json",
}
safeName = {".git, .vscode"}
dirIgnore = {".git", ".vscode"}

def dfs(pt):
    for x in pt.iterdir():
        s = str(x)
        if x.is_dir() and not any(s.endswith(y) for y in dirIgnore):
            dfs(x)
            continue
        name, ext = os.path.splitext(os.path.basename(s))
        if ext in safeExt: continue
        if any(name.endswith(n) for n in safeName): continue
        print(f"rm: {s}")
        try: os.remove(s)
        except: print("Failed ^^\n")

dfs(p)
