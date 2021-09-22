class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        R = len(rides)
        dp = [0] * R
        rides.sort(key = lambda x: x[1])
        ends = [r[1] for r in rides]
        for i,(s,e,t) in enumerate(rides):
            dp[i] = e-s+t
            if i >= 1: dp[i] = max(dp[i], dp[i-1])
            if i == 0: continue
            idx = bisect_right(ends, s)
            if ends[idx] > s: idx -= 1
            if idx == -1: continue
            dp[i] = max(dp[i], dp[idx] + e-s+t)

        return max(dp)
