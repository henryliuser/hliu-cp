intput = lambda : map(int, input().split())

def solve():
    ans = []
    r, g, b = sorted( intput() )
    df = [abs(r-g), abs(r-b), abs(g-b)]
    df = [(df[i],i) for i in range(3) if df[i]%3 == 0]
    for i, j in df:
        k = i // 3
        if j == 0: ans.append(g)
        if j == 1: ans.append(b)
        if j == 2: ans.append(b)
    if len(ans) == 0: return -1
    return min(ans)


T, = intput()
for _ in range(T):
    print( solve() )
