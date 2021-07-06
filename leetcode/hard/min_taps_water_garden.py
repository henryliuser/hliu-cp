class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        dp = [n+1] * (n+1)
        dp[0] = 0
        for i, r in enumerate(ranges):
            start = max(0, i-r)
            end = min(i+r, n)
            for j in range(start, end+1):
                dp[j] = min(dp[j], dp[start]+1)
        if dp[n] > n: return -1
        return dp[n]
        
