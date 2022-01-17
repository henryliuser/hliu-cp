# https://leetcode.com/problems/maximum-running-time-of-n-computers/
# binary search on max time
# max time requires n*g charge
# batteries > g charge will be wasted
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
