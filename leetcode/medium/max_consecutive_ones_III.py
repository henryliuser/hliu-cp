class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        ans = 0
        N = len(nums)
        lo, hi = 0, 0
        curr = 0
        while hi < N:
            curr += not nums[hi]
            while curr > k:
                curr -= not nums[lo]
                lo += 1
            hi += 1
            ans = max(ans, hi-lo)
        return ans
