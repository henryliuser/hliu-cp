class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        N = len(s)
        dp = [False] * (N+1)
        dp[0] = True
        for i in range(1,N+1):
            for w in wordDict:
                M = len(w)
                if i-M < 0: continue
                if not dp[i-M]: continue
                for j in range(M):
                    if s[i-M+j] != w[j]:
                        break
                else:
                    dp[i] = True

        return dp[-1]
