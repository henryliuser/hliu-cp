# https://codeforces.com/contest/1647/problem/C
# paint it backwards so as to not overwrite your previous work
import sys
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, M = intput()
    grid = [input() for _ in range(N)]

    ans = []
    if grid[0][0] == '1':
        return print(-1)

    for i in range(N-1,-1,-1):
        top = (i == 0)
        for j in range(M-1,-1,-1):
            x = grid[i][j]
            if top and j == 0: continue
            if x == '0': continue
            if not top:
                ans += [ (i, j+1, i+1, j+1) ]
            else:
                ans += [ (1, j, 1, j+1) ]

    print( len(ans) )
    for a in ans:
        print(*a)

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        solve()
