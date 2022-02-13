# https://leetcode.com/problems/maximum-and-sum-of-array/
# use ternary mask to store the state 0,1,2 of each slot
class Solution:
    def maximumANDSum(self, nums: List[int], S: int) -> int:
        N = len(nums)
        # base-3 bitmask
        dp = [[-1] * 3**S for _ in range(N)]
        p3 = [1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049]

        def qry(x, i):  # ternary bit at pos i from mask x
            return x % p3[i+1] // p3[i]

        def upd(x, i, y):  # ternary mask after setting x's i-th bit to y
            p = qry(x, i)
            return x + (y-p) * p3[i]

        def dfs(i, m):
            if i >= N: return 0
            if dp[i][m] != -1: return dp[i][m]

            res = 0
            for k in range(S):
                b = qry(m, k)
                if b == 2: continue
                nm = upd(m, k, b+1)
                x = nums[i] & (k+1)
                y = dfs(i+1, nm)
                res = max(res, x+y)
            dp[i][m] = res
            return res

        return dfs(0, 0)
        
