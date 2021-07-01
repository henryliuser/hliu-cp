class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        S, P = len(s), len(p)
        dp = [[False] * (P+1) for _ in range(S+1)]

        dp[0][0] = True  # '' pat matches '' str
        for c in range(P):  # matching p against ''
            if c > 0:  # only true if x* matches 0
                dp[0][c+1] = p[c] == '*' and dp[0][c-1]

        for r in range(S):
            for c in range(P):
                if p[c] == '*':
                    m0 = dp[r+1][c-1]  # match 0 chars
                    last = p[c-1]
                    if last == '.' or last == s[r]:  # match >= 1 chars
                        dp[r+1][c+1] = dp[r][c+1]
                    if m0:
                        dp[r+1][c+1] = True
                elif p[c] == '.' or s[r] == p[c]:
                    dp[r+1][c+1] = dp[r][c]

        for d in dp: print(list(map(int, d)))

        return dp[S][P]
