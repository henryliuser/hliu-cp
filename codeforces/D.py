import sys
from random import randint as rng
from collections import Counter, defaultdict
from bisect import bisect_left, bisect_right
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A = [input() for _ in range(N)]
    dp = []
    for s in A:
        if s == s[::-1]: return "YES"


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
