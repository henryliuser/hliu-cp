# https://atcoder.jp/contests/abc250/tasks/abc250_f
# first, we need to be able to efficiently compute the areas of
# any split between a pair of points
# the shoelace theorem from math:
# with X,Y sorted in CW or CCW order
# let j = (i+1) % N
# area = sum( X[i]*Y[j] - X[j]*Y[i] ) // 2
#
# with that in mind, we can use prefix sums to compute the
# sums for any continuous segment of points
# and compute the area of any split in O(1)
#
# we want to iterate over one end of the split `j`,
# and find the best corresponding point `i`.
# because it's convex, we see that the areas of the
# splits are monotonic on the range 0 <= i < j-1
# watch out for the edge case on j == N-1.
# final algorithm: loop on j, binary search for i, take the best
import sys
input = lambda: sys.stdin.readline().strip()
intput = lambda: map(int, input().split())

if __name__ == '__main__':
    N, = intput()
    X, Y = [0]*N, [0]*N
    for i in range(N):
        X[i], Y[i] = intput()

    pre = [0] * (N+1)  # sum of terms
    for i in range(N):
        j = (i+1) % N
        pre[i+1] = X[i] * Y[j] - X[j] * Y[i]
        pre[i+1] += pre[i]
    qtr, tot = pre[N], pre[N]*4
    def area(i, j) -> (int,int):
        dx = pre[j] - pre[i]
        a1 = (dx + X[j]*Y[i] - X[i]*Y[j]) * 4
        a2 = tot - a1
        return abs(a1), abs(a2)

    def bisect(l, r, j, qtr, b, area):
        if j == N-1: l = 1
        if j-l < 2: assert False
        ans = area(l,j)[b]
        while l < r:
            i = (l+r) >> 1
            v = area(i,j)[b]
            if (b and v >= qtr) or (not b and v <= qtr):
                r,ans = i,v
            else:
                l = i+1
        dx = abs(ans-qtr)
        if l > 0:
            v = area(l-1, j)[b]
            dx = min( dx, abs(qtr-v) )
        return dx

    ans = float('inf')
    for j in range(2, N):
        a = bisect(0, j-1, j, qtr, 0, area)
        b = bisect(0, j-1, j, qtr, 1, area)
        ans = min(ans, a, b)
    print(ans)
