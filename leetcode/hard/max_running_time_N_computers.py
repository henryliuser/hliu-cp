# https://leetcode.com/problems/maximum-running-time-of-n-computers/
# binary search on max time
# max time requires n*g charge
# batteries > g charge will be wasted

# 612 ms
class Solution:
    def maxRunTime(self, n: int, B: List[int]) -> int:
        B.sort()
        m = len(B)
        pre = [0] * (m+1)
        for i in range(m):
            pre[i+1] = B[i] + pre[i]
        def check(g):
            i = bisect_left(B, g)
            res = pre[i] + (m-i)*g
            return res >= n*g

        lo, hi = 1, int(1e18)
        while lo < hi:
            mid = (lo+hi+1)//2
            if check(mid): lo = mid
            else: hi = mid-1
        return lo

# 5531 ms
class Solution:
    def maxRunTime(self, n: int, B: List[int]) -> int:
        def check(g, res=0):
            for x in B:
                res += min(g, x)
            return res >= n*g

        lo, hi = 1, int(1e18)
        while lo < hi:
            mid = (lo+hi+1)//2
            if check(mid): lo = mid
            else: hi = mid-1
        return lo
