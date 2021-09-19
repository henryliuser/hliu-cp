class Solution:
    def jobScheduling(self, s: List[int], e: List[int], p: List[int]) -> int:
        N = len(p)
        dp = [0] * N
        sep = [ (s[i], e[i], p[i]) for i in range(N) ]
        sep.sort(key = lambda x : x[1])  # sort all entries by end time
        end = [j[1] for j in sep]        # sorted array of end times
        for i, (s,e,p) in enumerate(sep):
            dp[i] = p
            if i == 0: continue
            dp[i] = max(dp[i], dp[i-1])
            idx = bisect_left(end, s)
            if end[idx] > s: idx -= 1
            if idx < 0: continue
            dp[i] = max(dp[i], p + dp[idx])
        return dp[-1]
