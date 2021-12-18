t = int(input())
dirs = ( (0,1), (0,-1), (1,0), (-1,0), (1,1), (1,-1), (-1, 1), (-1, -1) )
def solve():
    h, w = map(int, input().split())
    ans = (0, [[0]*w for _ in range(h)])
    def newdir(d, x, y):
        nx, ny = x+d[0], y+d[1]
        if nx >= h: return (0,-1)
        if nx < 0:  return (0,1)
        if ny >= w: return (1,0)
        if ny < 0:  return (-1,0)
        return d

    def sim(r, c, dir):
        nonlocal ans, h, w
        dp = [[0]*w for _ in range(h)]
        perim = 2 * w + 2 * (h-2)
        curr = 0
        def check(x, y):
            for d in dirs:
                nx, ny = x+d[0], y+d[1]
                if 0 <= nx < h and 0 <= ny < w and dp[nx][ny] == 1:
                    return False
            return True
        for _ in range(perim):
            if check(r,c):
                curr += 1
                dp[r][c] = 1
            dir = newdir(dir, r, c)
            r,c = r+dir[0], c+dir[1]
        
        if curr > ans[0]: ans = (curr, dp)

    for r in range(h):
        for c in range(w):
            if r == 0: sim(r,c, (0,1))
            if c == 0: sim(r,c, (-1,0))
            if r == h: sim(r,c, (0,-1))
            if c == w: sim(r,c, (1,0))

    return ans[1]

for _ in range(t):
    a = solve()
    for x in a:
        for y in x: print(y, end="")
        print()
