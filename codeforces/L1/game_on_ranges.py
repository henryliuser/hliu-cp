# https://codeforces.com/contest/1623/problem/B
import sys
from collections import defaultdict
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    Ls = defaultdict(list)
    for _ in range(N):
        l, r = intput()
        Ls[l].append(r)
    for l in Ls: Ls[l].sort()

    for l in sorted(Ls):
        A = Ls[l]
        M = len(A)
        for i in range(M):
            if len(A) == 1:
                print(l, A[0], l)
            else:
                print(l, A[-1], A[-2]+1)
            A.pop()

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        solve()
