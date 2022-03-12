# https://codeforces.com/contest/1652/problem/B
# there was a way better/cooler way to check this:
# if theres ever a 2x2 square with area == 3, return "NO", else "YES"
import sys, os
from bisect import *
from itertools import *
from collections import *

inf    = float('inf')
dfd    = defaultdict
enum   = enumerate
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

dirs = [(0,1), (1,0), (-1,0), (0,-1)]

def solve():
    N, M = intput()
    grid = [input() for _ in range(N)]
    seen = [[0]*M for _ in range(N)]
    def dfs(i,j,s):
        cnt = 1
        seen[i][j] = 1
        s[0] = min(s[0], i)
        s[1] = max(s[1], i)
        s[2] = min(s[2], j)
        s[3] = max(s[3], j)
        for x,y in dirs:
            r, c = x+i, y+j
            if 0 <= r < N and 0 <= c < M:
                if not seen[r][c] and grid[r][c] == '1':
                    cnt += dfs(r,c,s)
        return cnt

    for i in range(N):
        for j in range(M):
            if seen[i][j]: continue
            if grid[i][j] == '0': continue
            s = [inf, -1, inf, -1]
            c = dfs(i,j,s)
            dx = s[1] - s[0] + 1
            dy = s[3] - s[2] + 1
            if c != dx * dy:
                return "NO"
    return "YES"

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
