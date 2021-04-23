class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curr = ans = nums[0]
        for i in range(1, len(nums)):
            n = nums[i]
            curr = max(n, curr + n) # take it or start over
            ans = max(ans, curr)
        return ans


                
