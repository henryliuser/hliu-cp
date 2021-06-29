class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k == 0 or k == 1: return 0
        curr = 1
        lo = ans = 0
        N = len(nums)
        for hi in range(N):
            curr *= nums[hi]
            while curr >= k:
                curr //= nums[lo]
                lo += 1
            ans += hi - lo + 1
        return ans
