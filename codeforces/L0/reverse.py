import sys
from random import randint as rng
from collections import Counter, defaultdict
from bisect import bisect_left, bisect_right
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    a = b = -1
    N, = intput()
    A = list(intput())
    for i in range(N):
        if A[i] != i+1:
            a = i
            break
    else: return A
    if a == N-1: return A
    m = N+1
    for j in range(a+1, N):
        if A[j] == a+1:
            b = j
            break

    return A[:a] + A[a:b+1][::-1] + A[b+1:]


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( *solve() )
