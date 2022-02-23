
import sys
from math import sqrt
from random import randint as rng
from collections import Counter, defaultdict
from bisect import bisect_left, bisect_right
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def dist(a,b,c,d):
    dx = c-a
    dy = d-b
    return sqrt( dx*dx + dy*dy )

def solve():
    a,b = intput()
    c,d = intput()
    e,f = intput()
    if b == d and f < b: return dist(a,b,c,d)
    if b == f and d < b: return dist(a,b,e,f)
    if d == f and b < d: return dist(c,d,e,f)
    return 0

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
