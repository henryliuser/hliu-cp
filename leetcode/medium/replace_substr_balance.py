class Solution:
    def balancedString(self, s: str) -> int:
        N = len(s)
        letters = ('Q', 'W', 'E', 'R')
        ans = float('inf')
        c = defaultdict(int)
        for ch in s: c[ch] += 1
        target = {k: N//4 - c[k] for k in letters}
        if sum(v for k,v in target.items() if v > 0) == 0:
            return 0
        curr = {k:0 for k in letters}
        lo, hi = 0, 0
        while hi < N:
            ch = s[hi]
            curr[ch] += 1
            while all(v >= -target[k] for k,v in curr.items() if target[k] < 0):
                ans = min(ans, hi-lo + 1)
                curr[s[lo]] -= 1
                lo += 1
            hi += 1
        return ans






        
