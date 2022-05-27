# https://atcoder.jp/contests/abc211/tasks/abc211_e
# learned how to backtrack polyominos I guess
# and just hash the entire board
# ull 219ms  vs.  1d grid 369ms  vs.  2d grid >500ms
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    K, = intput()

    ull = 0
    for i in range(N):
        for j,c in enumerate(input()):
            if c == '.': continue
            ull ^= 1 << (i*N+j)

    ans = 0
    vis = set()
    dirs = [ (0,1), (1,0), (-1,0), (0,-1) ]

    def dfs(k, p):
        nonlocal ull, ans
        # k: available, p: {taken}
        if ull in vis: return
        vis.add(ull)
        if k == 0:
            ans += 1
            return

        for i,j in p:
            for x,y in dirs:
                x,y = i+x, j+y
                if x < 0 or x >= N or y < 0 or y >= N: continue
                h = x*N+y
                if ull & (1 << h): continue
                ull ^= 1 << h
                p += [ (x,y) ]
                dfs(k-1, p)
                p.pop()
                ull ^= 1 << h

    for i in range(N):
        for j in range(N):
            k = i*N+j
            if ull & (1 << k): continue
            p = [ (i,j) ]
            ull ^= (1 << k)
            dfs(K-1,p)
            ull ^= (1 << k)

    return ans

if __name__ == '__main__':
    print( solve() )
