class Solution:
    def balancedString(self, s: str) -> int:
        N = len(s)
        letters = ('Q', 'W', 'E', 'R')
        ans = float('inf')
        count = defaultdict(int)
        for ch in s: count[ch] += 1
        target = {k: count[k] - N//4 for k in letters}
        target = {k:v for k,v in target.items() if v > 0}
        if len(target) == 0: return 0
        curr = {k:0 for k in letters}
        lo, hi = 0, 0
        while hi < N:
            curr[s[hi]] += 1
            while all(curr[k] >= target[k] for k in target):
                ans = min(ans, hi-lo + 1)
                curr[s[lo]] -= 1
                lo += 1
            hi += 1
        return ans
