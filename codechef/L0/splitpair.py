import sys
from bisect import *
from collections import *
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    S = [*map(int, input())]
    j = S.pop() % 2
    return "YES" if any(x%2==j for x in S) else "NO"


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
