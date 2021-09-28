intput = lambda : map(int, input().split())
xdirs = ((-1, -1), (-1,1), (1,-1), (1,1))

def process(r, c, g):
    seen = { (r,c) }
    i, j = r-1, c-1
    k, l = r-1, c+1
    size = 0
    while g[i][j] == g[k][l] == '*':
        size += 1
        seen.add( (i,j) )
        seen.add( (k,l) )
        i, j = i-1, j-1
        k, l = k-1, l+1
    return (size, seen)

def solve():
    marks = 0
    ticks = []
    seen = set()
    n, m, k = intput()
    grid = ['.'*(m+2)]
    grid += ['.' + input() + '.' for _ in range(n)]
    grid += ['.'*(m+2)]
    for r in range(1, n+1):
        for c in range(1, m+1):
            if grid[r][c] != '*': continue
            marks += 1
            if grid[r-1][c-1] == '.': continue
            if grid[r-1][c+1] == '.': continue
            p = process(r, c, grid)
            ticks.append(p)
    if marks == 0: return "YES"
    for s,t in reversed(sorted(ticks)):
        if s < k: break
        for (x,y) in t:
            seen.add( (x,y) )
        if len(seen) == marks:
            return "YES"
    return "NO"

t, = intput()
for i in range(t):
    print( solve() )
