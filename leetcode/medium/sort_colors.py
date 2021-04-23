class Solution:
    def sortColors(self, nums: List[int]) -> None:
        counts = {0:0, 1:0, 2:0}
        for x in nums:
            if x in counts: counts[x] += 1
            else: counts[x] = 1
        a, b, c = counts[0], counts[1], counts[2]
        for x in range(a):
            nums[x] = 0
        for x in range(b):
            nums[a+x] = 1
        for x in range(c):
            nums[a+b+x] = 2
            
