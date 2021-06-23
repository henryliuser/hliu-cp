class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        ans = 0
        N = len(s)
        lo, hi = 0, 0
        count = {'a':0, 'b':0, 'c':0}
        while hi < N:
            ch = s[hi]
            count[ch] += 1
            while all(count.values()):
                ans += N - hi
                count[s[lo]] -= 1
                lo += 1
            hi += 1
        return ans
            
