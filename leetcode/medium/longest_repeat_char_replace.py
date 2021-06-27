class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        N = len(s)
        lo = ans = 0
        window = defaultdict(int)
        for hi in range(N):
            window[s[hi]] += 1
            while hi-lo+1 - max(window.values()) > k:
                window[s[lo]] -= 1
                if not window[s[lo]]:
                    window.pop(s[lo])
                lo += 1
            ans = max(ans, hi-lo+1)
                
        return ans
