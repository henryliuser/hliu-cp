# https://leetcode.com/problems/rearrange-array-elements-by-sign/
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        A = [[], []]
        N = len(nums)
        for x in nums:
            if x > 0: A[0] += [x]
            if x < 0: A[1] += [x]
        res = []
        for i in range(N):
            res += [ A[i%2][i//2] ]
        return res
            
