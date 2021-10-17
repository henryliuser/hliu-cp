class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        N = len(nums)
        ans = [0, 0]
        def dfs(i, s):
            nonlocal ans
            if i == N:
                if s == 0: return
                if s == ans[0]:
                    ans[1] += 1
                if s > ans[0]:
                    ans = [s, 1]
                return
            dfs(i+1, s | nums[i])
            dfs(i+1, s)
        dfs(0, 0)
        return ans[1]
                
