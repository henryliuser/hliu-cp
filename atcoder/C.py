import sys
from bisect import *
from collections import *

dfd    = defaultdict
enum   = enumerate
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    xs = dfd(list)
    for i in range(N):
        x,y = intput()
        xs[y] += [(x,i)]
    S = input()
    for L in xs.values():
        r = 0
        L.sort()
        sz = len(L)
        for j in range(sz):
            x,i = L[j]
            if r and S[i] == 'L':
                return "Yes"
            if S[i] == 'R':
                r = 1
    return "No"

if __name__ == '__main__':
    print( solve() )
