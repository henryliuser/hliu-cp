import sys
from random import randint as rng
from collections import Counter, defaultdict
from bisect import bisect_left, bisect_right
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, K = intput()
    A = list(intput())
    B = list(intput())
    C = sorted(zip(A,B))
    for a,b in C:
        if K >= a:
            K += b
        else:
            break
    return K

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
