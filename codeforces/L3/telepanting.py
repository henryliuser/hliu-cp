# https://codeforces.com/problemset/problem/1552/F
# incredible question
import sys
from bisect import *
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
Q = 998244353

add = lambda x,y : (x + y) % Q

if __name__ == '__main__':
    xs = []
    N, = intput()

    ans = 0
    dp = [0] * N
    ps = [0] * (N+1)
    for i in range(N):
        x,y,s = intput()
        xs += [x]
        j = bisect_left(xs, y)
        dist = x - y
        qs = add(ps[i], -ps[j])
        dp[i] = add(dist, qs)
        ps[i+1] = add(dp[i], ps[i])
        if s == 1:
            ans = add(ans, dp[i])

    ans = add(ans, xs[-1]+1)
    print(ans)
