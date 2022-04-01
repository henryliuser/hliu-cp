# https://codeforces.com/contest/1658/problem/C
# just observation, shape rotate it
import sys
from bisect import *
from collections import *
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A = [*intput()]
    if N == 1:
        return "YES" if A[0] == 1 else "NO"

    if A.count(1) != 1: return "NO"
    A += [ A[0] ]
    for i in range(1, N+1):
        dx = A[i] - A[i-1]
        # if A[i-1] == N and A[i] != 1: return "NO"  # already implicit
        if dx > 1: return "NO"

    return "YES"


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
