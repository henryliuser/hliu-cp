import sys
from bisect import *
from collections import *
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
enum   = enumerate
dfd    = defaultdict

INF = float("inf")

def solve():
    A = [*intput()]
    B = [*intput()]
    C = [*intput()]
    cur = 0
    ans = [0] * 4
    lim = int(1e6)
    for i in range(4):
        ans[i] = min(l[i] for l in (A,B,C))
        if cur + ans[i] >= lim:
            ans[i] = lim-cur
            break
        cur += ans[i]
    else:
        return print("IMPOSSIBLE")

    return print(*ans)

if __name__ == '__main__':
    T, = intput()
    for t in range(1,T+1):
        print(f"Case #{t}: ", end='')
        solve()
