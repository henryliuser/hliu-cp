# https://leetcode.com/problems/count-the-hidden-sequences/
class Solution:
    def numberOfArrays(self, diff: List[int], lower: int, upper: int) -> int:
        cur = 0
        N = len(diff)
        lo, hi = lower, upper
        for i in range(N):
            d = diff[i]
            cur += d
            if cur < 0: lo = max(lo, lower-cur)
            if cur > 0: hi = min(hi, upper-cur)
        return max(0, hi-lo+1)
