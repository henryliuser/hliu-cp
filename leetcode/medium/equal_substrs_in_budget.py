class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        N = len(s)
        lo = ans = 0
        cost = 0
        for hi in range(N):
            ti, si = t[hi], s[hi]
            hi_diff = abs(ord(ti) - ord(si))
            cost += hi_diff
            if cost <= maxCost: ans = max(ans, hi-lo+1)
            while cost > maxCost:
                to, so = t[lo], s[lo]
                lo_diff = abs(ord(to) - ord(so))
                cost -= lo_diff
                lo += 1
        return ans
