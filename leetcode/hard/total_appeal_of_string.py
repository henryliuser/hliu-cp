# https://leetcode.com/contest/weekly-contest-291/problems/total-appeal-of-a-string/
class Solution:
    def appealSum(self, s: str) -> int:
        N = len(s)
        cnt = [0] * 26
        #   = # of substrs ending at i containing x

        ans = dp = 0
        for i in range(1, N+1):  # sum of appeal in substrs ending at s[i-1]
            x = ord(s[i-1]) - ord('a')
            dp += i - cnt[x]
            cnt[x] = i
            ans += dp

        return ans
