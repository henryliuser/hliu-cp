# https://leetcode.com/contest/weekly-contest-302/problems/minimum-deletions-to-make-array-divisible/
class Solution:
    def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
        g = numsDivide[0]
        for x in numsDivide:
            g = gcd(g, x)

        nums.sort()
        for i,x in enumerate(nums):
            if g % x == 0:
                return i
        return -1
