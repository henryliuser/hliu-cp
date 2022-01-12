# https://codeforces.com/contest/1624/problem/F
# ... sad
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def query(c):
    print('+', c)
    sys.stdout.flush()
    x, = intput()
    return x

def submit(x):
    print('!', x)
    sys.stdout.flush()

def solve():
    d = 1
    N, = intput()
    lo, hi = 1, N-1

    while lo < hi:
        # ml = (d*N) - hi
        # mh = (d*N) - lo
        # qry = (ml + mh) // 2
        mid = (lo + hi + 1) // 2  # crucial line
        qry = (d*N) - mid
        if qry == 0 or qry == N: break
        q = query(qry)
        if q != d:
            hi = mid-1  # crucial line
        if q == d:
            lo = mid
            d += 1
        lo, hi = lo+qry, hi+qry

    submit(lo)

if __name__ == '__main__':
    solve()
