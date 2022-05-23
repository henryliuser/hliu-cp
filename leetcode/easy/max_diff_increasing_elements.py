class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        ans = -1
        N = len(nums)
        smax = [0] * N
        smax[-1] = nums[-1]
        for i in range(N-2, -1, -1):
            smax[i] = max(nums[i], smax[i+1])

        for i in range(N-1):
            x = nums[i]
            if x < smax[i+1]:
                ans = max(ans, smax[i+1] - x)
        return ans
            
