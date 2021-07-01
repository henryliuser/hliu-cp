# O(SP) time, O(P) memory
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        S, P = len(s), len(p)
        dp = [[False] * (P+1) for _ in range(2)]

        dp[0][0] = True  # '' pat matches '' str
        for c in range(P):  # matching p against ''
            if c > 0:  # only true if x* matches 0
                dp[0][c+1] = p[c] == '*' and dp[0][c-1]

        # dp[r][c] = p[0:c] matches s[0:r]
        for r in range(S):
            t = (r+1) % 2
            nt = not t
            for c in range(P):
                if p[c] == '*':
                    m0 = dp[t][c-1]  # match 0 chars
                    last = p[c-1]
                    if last == '.' or last == s[r]:  # match >= 1 chars
                        dp[t][c+1] = dp[nt][c+1]
                    if m0:
                        dp[t][c+1] = True
                elif p[c] == '.' or s[r] == p[c]:
                    dp[t][c+1] = dp[nt][c]

            for x in range(len(dp[nt])):  # have to reset
                dp[nt][x] = False

        return dp[S%2][P]

# O(SP) time, O(SP) memory
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        S, P = len(s), len(p)
        dp = [[False] * (P+1) for _ in range(S+1)]

        dp[0][0] = True  # '' pat matches '' str
        for c in range(P):  # matching p against ''
            if c > 0:  # only true if x* matches 0
                dp[0][c+1] = p[c] == '*' and dp[0][c-1]

        # dp[r][c] = p[0:c] matches s[0:r]
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

        return dp[S][P]
