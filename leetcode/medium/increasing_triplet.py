


# LIS cheese solution: O(N log N) time, O(N) space
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        ans = 0
        N = len(nums)
        dp = [0] * N
        for x in nums:
            lo, hi = 0, ans
            while lo < hi:
                mid = (lo + hi) // 2
                if dp[mid] < x: lo = mid + 1
                else: hi = mid
            dp[lo] = x
            if lo == ans: ans += 1
        return ans >= 3
