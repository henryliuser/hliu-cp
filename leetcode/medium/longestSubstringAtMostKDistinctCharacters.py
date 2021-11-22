class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        N = len(s)
        i = ans = 0
        curr = defaultdict(int)
        for j in range(N):
            curr[ s[j] ] += 1
            while len(curr) > k:
                curr[ s[i] ] -= 1
                if curr[ s[i] ] <= 0:
                    del curr[ s[i] ]
                i += 1
            ans = max(ans, j-i+1)
        return ans
