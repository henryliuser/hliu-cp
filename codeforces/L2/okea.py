# https://codeforces.com/contest/1634/problem/C
# lame
# 1 3 5
# 2 4 6
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    src = 0
    N, K = intput()
    if N % 2 and K > 1: raise OSError()
    grid = [[-1]*K for _ in range(N)]
    for i in range(N):
        for j in range(K):
            grid[i][j] = 1+i+N*j
    return grid

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        try:
            s = solve()
            print("YES")
            for q in s:
                print(*q)
        except:
            print("NO")
