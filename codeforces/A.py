import sys
from random import randint as rng
from collections import Counter, defaultdict
from bisect import bisect_left, bisect_right
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A = list(intput())
    B = list(intput())
    for i in range(N):
        if B[i] > A[i]:
            A[i], B[i] = B[i], A[i]
    return max(A) * max(B)


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
