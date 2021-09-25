class Solution:
    def validSubarrays(self, nums: List[int]) -> int:
        st = []
        ans = 0
        N = len(nums)
        nse = [-1] * N
        for i,x in enumerate(nums):
            while st and x < nums[st[-1]]:
                nse[st.pop()] = i
            st.append(i)
        for i,x in enumerate(nums):
            if nse[i] == -1: nse[i] = N
            ans += nse[i]-i
        return ans
