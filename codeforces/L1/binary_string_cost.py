# https://codeforces.com/contest/1680/problem/C
# binary search + 2p, pretty educational
# binary search on the best cost with 0's being the limiting factor,
# then repeat with 1's and take the minimum.
# cost: max(remaining 0's, removed 1's)
# limiting factor is x: suppose the max of the 2 values is given by x
# check(guess): consider all possible subarrays where val(x) <= guess
# if the best answer we achieved in those subarrays is <= mid, guess lower
# else, guess higher
import sys
input = lambda: sys.stdin.readline().strip()
intput = lambda: map(int, input().split())
v = lambda x : int(x)

def solve():
    S = input()
    N = len(S)
    cnt = [0,0]
    for x in S:
        cnt[v(x)] += 1

    def bisect(l, r, p):
        while l < r:
            m = (l+r) // 2
            q = p(m)
            if q <= m: r = q
            else: l = m+1
        return l

    def twoPtrs(c, cmp):
        def tp(m):
            i = 0
            cur = [0,0]
            ans = float('inf')
            for j in range(N):
                cur[v( S[j] )] += 1
                while i < j and cmp(cur[c]) > m:
                    cur[v( S[i] )] -= 1
                    i += 1
                ans = min(ans, max(cnt[1]-cur[1], cur[0]))
            return ans
        return tp

    cmp0 = lambda c: c
    cmp1 = lambda c: cnt[1] - c
    a = bisect( 0, cnt[0], twoPtrs(0, cmp0) )
    b = bisect( 0, cnt[1], twoPtrs(1, cmp1) )
    return min(a, b)

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
