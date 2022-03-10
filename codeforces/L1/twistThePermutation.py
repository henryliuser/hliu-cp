# https://codeforces.com/contest/1650/problem/D
# just sim backwards 
import sys
from random import randint as rng
from collections import Counter, defaultdict
from bisect import bisect_left, bisect_right
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A = [*intput()]

    idx = [-1] * (N+1)
    for i in range(N):
        idx[A[i]] = i+1

    def shift(x,k):
        nonlocal A
        B = [0] * N
        for i in range(x):
            j = (i-k)%x
            B[j] = A[i]
            idx[A[i]] = j+1
        A = B

    ans = []
    for x in range(N, 0, -1):
        i = idx[x]
        res = (i-x)%x
        shift(x, res)
        ans += [res]
    # if state != 0: return []  # gambling
    return ans[::-1]

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        s = solve()
        if not s: print(-1)
        else: print(*s)
