# https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
# easier than #2 and #3
class Solution:
    def numberOfWays(self, A: str) -> int:
        S = []
        for i,ch in enumerate(A):
            if ch == 'S':
                S += [i]
        M = len(S)
        if M % 2 or M == 0: return 0
        
        ans = 1
        for i in range(1, M-1, 2):
            dx = S[i+1]-S[i]
            ans *= dx
        return ans % int(1e9+7)
