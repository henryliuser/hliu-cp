# https://codeforces.com/problemset/problem/1521/B
# one of the worst solutions i've ever written tbh
import sys
from math import gcd
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
M1 = int(1e9+7)
M2 = int(1e9+9)

def solve():
    ans = []
    N, = intput()
    A  = list(intput())
    for i in range(1, N):
        x, y = A[i-1], A[i]
        if gcd(x, y) == 1:
            continue
        x = min(x, y)
        A[i-1], A[i] = M1, x
        if i >= 2 and A[i-2] == M1: A[i-1] = M2
        ans += [ (i, i+1, A[i-1], A[i]) ]
    return ans


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        s = solve()
        print(len(s))
        for q in s: print(*q)
        # assert all(gcd(A[i-1], A[i]) == 1 for i in range(1, len(A)))
