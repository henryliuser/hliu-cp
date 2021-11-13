class Solution:
    def countVowels(self, word: str) -> int:
        ans = 0
        N = len(word)
        vows = {'a', 'e', 'i', 'o', 'u'}
        dp = [0] * (N+1)
        for i, ch in enumerate(word, start=1):
            dp[i] = dp[i-1]
            if ch in vows:
                dp[i] += i
            ans += dp[i]
        return ans

        
