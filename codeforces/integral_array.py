# https://codeforces.com/contest/1648/problem/B
# somehow it's C log C lol
# really cool problem though. For every missing number r,
# loop on all existing numbers y < C/r
# let y*r <= x < y*(r+1)
# and prefix sum/binary search to see if any x's exist. if so, violation
import sys
from bisect import *

input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, C = intput()
    A = sorted(set(intput()))
    if A[0] != 1: return "No"

    for r in range(2, C//2+1):
        i = bisect_left(A, r)
        if i >= len(A) or A[i] == r: continue
        for y in A:
            if y > C//r: break
            xl = y * r
            xr = y * (r+1) - 1
            i = bisect_left(A, xl)
            j = bisect_right(A, xr)
            if j-i > 0: return "No"

    return "Yes"


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
