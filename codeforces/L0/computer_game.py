import sys
from random import randint as rng
from collections import Counter, defaultdict
from bisect import bisect_left, bisect_right
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    s = [list(input()) for _ in range(2)]
    for i in range(N):
        if s[0][i] == s[1][i] == '1':
            return "NO"
    return "YES"

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
