# This dp is useless because in-degree of all is only 1.
# However, this handles the case where that's not true as well.
class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        dp = {}
        def dfs(x, L, seen):
            if x in dp:
                L[0] = len(seen) + dp[x][0]
                return
            seen.add(x)
            if nums[x] not in seen:
                dfs(nums[x], L, seen)
            else:
                L[0] = len(seen)
            dp[x] = L
        for n in nums:
            if n in dp: continue
            dfs(n, [0], set())
        return max(y[0] for y in dp.values())
