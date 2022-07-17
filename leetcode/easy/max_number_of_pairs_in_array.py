# https://leetcode.com/contest/weekly-contest-302/problems/maximum-number-of-pairs-in-array/
class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        ans = [ 0, len(nums) ]
        for k,v in Counter(nums).items():
            ans[0] += v//2
            ans[1] -= v//2*2
        return ans

        
