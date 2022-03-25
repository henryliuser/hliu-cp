import sys
from bisect import *
from collections import *
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
enum   = enumerate
dfd    = defaultdict

"""
100
50 50
25 25 50
12 13 25 50

"""
def solve():
    N, = intput()
    A = sorted( intput() )
    ps = [0] * (N+1)
    for i in range(N):
        ps[i+1] = ps[i] + A[i]

    def bisearch(x, l, r):
        while l < r:
            m = (l+r)//2
            if ps[m] >= x: r = m
            else: l = m+1
        return l

    def dfs(x, l, r):
        if x == 1: return
        a = x // 2
        b = ps[N]-a
        i = bisearch(a,l,r)
        if i > r or i < l or ps[i] != a:
            raise OSError()
        dfs(a,l,i), dfs(b,i+1,r)

    try:
        dfs(ps[N], 0, N)
        return "YES"
    except OSError:
        return "NO"



if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
