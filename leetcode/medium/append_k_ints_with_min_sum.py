# https://leetcode.com/contest/weekly-contest-283/problems/append-k-integers-with-minimal-sum/
class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        c = 0
        mx = k+1
        s = k * (k+1) // 2
        for x in sorted(set(nums)):
            if x <= mx:
                s -= x
                s += mx
                mx += 1
        return s
