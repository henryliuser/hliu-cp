class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        x = sorted(((n, i) for i, n in enumerate(nums)))
        return x[-1][0] * x[-2][0] - x[0][0] * x[1][0]
