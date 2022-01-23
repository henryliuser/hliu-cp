import sys
from random import randint as rng
from collections import Counter, defaultdict
from bisect import bisect_left, bisect_right
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    L, R, K = intput()
    if K == 0 and L == R and L != 1: return True
    if K == 1 and L == R == 1: return True
    N = R-L+1
    if N % 2 == 0:
        return (N//2) <= K
    else:
        if L % 2:
            return (N+1)//2 <= K
        else:
            return (N//2) <= K

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( "YES" if solve() else "NO" )
