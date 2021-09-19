class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        N = len(nums)
        beauty = 0
        mx = [0] * N
        mn = [0] * N
        mx[0], mn[-1] = nums[0], nums[-1]

        def check2(i):
            return mx[i-1] < nums[i] < mn[i+1]

        def check1(i):
            return nums[i-1] < nums[i] < nums[i+1]

        for i in range(1, N):
            n = nums[i]
            mx[i] = max(mx[i-1], n)
        for i in range(N-2, -1, -1):
            n = nums[i]
            mn[i] = min(mn[i+1], n)

        for i in range(N):
            if not 0 < i < N-1: continue
            if   check2(i): beauty += 2
            elif check1(i): beauty += 1
        return beauty
