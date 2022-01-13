# https://codeforces.com/contest/1625/problem/B
# binary search, check with prefix sum offline range query
import sys
from random import randint as rng
from collections import Counter, defaultdict
from bisect import bisect_left, bisect_right
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A  = list(intput())

    def check(sz):
        if sz == 0: return False
        add = [[] for _ in range(sz+1)]
        rem = [[] for _ in range(sz+1)]
        for i in range(N):
            L, R = 0, sz-1
            if i < sz-1: # restrict some
                R = min(R, i)
            if i > N-sz: # restrict some
                L = max(L, sz-N+i)
            if L > R: continue
            add[L]   += [ A[i] ]
            rem[R+1] += [ A[i] ]

        cur = set()
        for i in range(sz):
            for x in rem[i]: cur.remove(x)
            for x in add[i]:
                if x in cur: return True
                cur.add(x)
        return False

    lo, hi = 0, N-1
    while lo < hi:
        mid = (lo+hi+1) // 2
        if check(mid): lo = mid
        else: hi = mid-1
    return -1 if lo == 0 else lo


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
