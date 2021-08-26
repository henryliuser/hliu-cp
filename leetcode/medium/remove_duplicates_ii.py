# O(N), O(1) stefan pochmann solution
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        ans = 0
        for n in nums:
            if ans < 2 or n != nums[ans-2]:
                nums[ans] = n
                ans += 1
        return ans
            
