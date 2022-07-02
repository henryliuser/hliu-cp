# https://leetcode.com/contest/biweekly-contest-81/problems/number-of-distinct-roll-sequences/
class Solution:
    def distinctSequences(self, n: int) -> int:
        if n == 1: return 6
        if n == 2: return 22
        Q = int(1e9+7)
        dp = [[0]*7 for _ in range(7)]
        for i in range(1, 7):
            for j in range(1, 7):
                if i == j: continue
                if gcd(i,j) != 1: continue
                dp[i][j] = 1


        for _ in range(n-2):
            dp2 = [[0]*7 for _ in range(7)]
            for x in range(1, 7):
                for j in range(1, 7):
                    if j == x: continue
                    if gcd(j, x) != 1: continue
                    for i in range(1, 7):
                        if i == x: continue
                        dp2[j][x] = (dp2[j][x] + dp[i][j]) % Q
            dp = dp2


        return sum( sum(x) for x in dp ) % Q
                        
