class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        N = len(s)
        i = ans = 0
        curr = defaultdict(int)
        for j in range(N):
            curr[s[j]] += 1
            while curr[s[j]] > 1:
                curr[s[i]] -= 1
                i += 1
            ans = max(ans, j-i+1)
        return ans
