# https://leetcode.com/contest/weekly-contest-302/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        ans = -1
        dp = defaultdict(int)
        for x in nums:
            s = sum(map(int, str(x)))
            if s in dp:
                ans = max(ans, x + dp[s])
            dp[s] = max(dp[s], x)
        return ans
            
