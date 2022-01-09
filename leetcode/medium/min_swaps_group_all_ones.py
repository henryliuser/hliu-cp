class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        N, o = len(nums), sum(nums)
        aug = nums + nums
        pre = [0] * (2*N+1)
        for i in range(2*N):
            pre[i+1] = pre[i] + aug[i]

        ans = N
        for i in range(N):
            p = pre[i+o] - pre[i]
            ans = min(ans, o-p)
        return ans
