import sys
from bisect import *
from collections import *
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
enum   = enumerate
dfd    = defaultdict

def solve():
    N, = intput()
    A = sorted( intput() )
    cur = 1
    for i in range(N):
        if A[i] < cur:
            continue
        cur += 1
    return print(cur-1)


if __name__ == '__main__':
    T, = intput()
    for t in range(1,T+1):
        print(f"Case #{t}: ", end='')
        solve()
