class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        ans = 0
        N = len(nums)
        for i in range(N):
            for j in range(i+1, N):
                if abs(nums[i] - nums[j]) == k:
                    ans += 1
        return ans
