# O(???) Bogosort beats 95% lol
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        while True:
            for c in range(len(nums)-1):
                if nums[c]*2 == nums[c-1] + nums[c+1]:
                    random.shuffle(nums)
                    break
            else: return nums

# O(N log N)
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        ans = []
        N = len(nums)
        A = sorted(nums)
        for x in range(N//2):
            ans.append(A[x])
            ans.append(A[~x])
        if N % 2 == 1:
            ans.append(A[N//2])
        return ans
