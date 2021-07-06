class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        # jump game II O(N) greedy
        maxes = [0] * len(ranges)
        for i, r in enumerate(ranges):
            start = max(0, i-r)
            sub = min(i-r, 0)
            maxes[start] = max(maxes[start], 2 * r + sub)

        ans = 0
        prev = right = 0
        for i, m in enumerate(maxes):
            if i > right: return -1
            if i > prev:
                ans += 1
                prev = right
            right = max(right, (i if m != 0 else 0)+m)
        return ans

        # DP O(200*N)
        dp = [n+1] * (n+1)
        dp[0] = 0
        for i, r in enumerate(ranges):
            start = max(0, i-r)
            end = min(i+r, n)
            for j in range(start, end+1):
                dp[j] = min(dp[j], dp[start]+1)
        if dp[n] > n: return -1
        return dp[n]
