import sys
from bisect import *
from collections import *
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
enum   = enumerate
dfd    = defaultdict

def solve():
    N, = intput()
    M = sum(map(int, str(N))) % 2
    for i in range(N+1, 3*N):
        ds = sum(map(int, str(i)))
        if ds % 2 != M: return i

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
