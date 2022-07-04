# https://leetcode.com/contest/biweekly-contest-81/problems/maximum-xor-after-operations/
class Solution:
    def maximumXOR(self, nums: List[int]) -> int:
        return reduce(or_, nums, 0)
        
