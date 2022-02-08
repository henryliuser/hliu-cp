# https://atcoder.jp/contests/abc236/tasks/abc236_e
# super instructive question
# use binary search:
# MEAN: (a+b+c+ ...) / N
# Check if possible mean g:
# (a+b+c+ ...) / N >= g
# (a+b+c+ ...) >= g*N
# (a-g + b-g + c-g + ...) >= 0
# now, dp to maximize it and check if greater than 0
# by reframing the algebra, we can greedily compute
# some maximal value instead of guesswork with sequence length
# MEDIAN: same idea but just ensure (# >= g) is > (# < g)
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def greed(g, f):
    dp = [0] * N
    dp[-1] = max(0, f(N-1, g))
    for i in range(N-2, -1, -1):
        dp[i] = f(i,g) + dp[i+1]
        if i+1 < N:
            v = f(i+1, g)
            d = 0 if i+2 >= N else dp[i+2]
            dp[i] = max(dp[i], v+d)
    return dp[0]

def bisect(p, lo, hi, eps, i=True):
    res = -1
    while hi-lo > eps:
        mid = (lo+hi)/2
        if i: mid = int(mid)
        if p(mid): lo = res = mid
        else: hi = mid
    return res

if __name__ == '__main__':
    N, = intput()
    A  = list(intput())

    mx = max(A)
    favg = lambda i,x: A[i] - x
    fmed = lambda i,x: 1 if A[i] >= x else -1
    pavg = lambda g : greed(g, favg) >= 0
    pmed = lambda g : greed(g, fmed) > 0
    avg = bisect(pavg, 0, mx+1, 1e-5, False)
    med = bisect(pmed, 0, mx+1,    1,  True)
    print(avg)
    print(med)
