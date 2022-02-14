import sys
from random import randint as rng
from collections import Counter, defaultdict
from bisect import bisect_left, bisect_right
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    P = list(intput())

    cur = -1
    comps = []
    for x in P:
        if x > cur:
            comps += [x]
            cur = x
        else:
            mx = -1
            while comps and comps[-1] > x:
                mx = max(mx, comps.pop())
            comps += [mx]
    return len(comps)



if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
