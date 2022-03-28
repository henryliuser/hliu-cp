# https://leetcode.com/problems/consecutive-numbers-sum/s
class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        # let k = number of terms
        # N = x + (x+1) + (x+2) + (x+3) + ... + (x+k-1)
        #   = kx + (1 + 2 + 3 + ... + k-1)
        #   = kx + k(k-1)/2
        # rearranging, we have:
        # kx = N - k(k-1)/2
        # Loop on k and check RHS is divisible by k
        # ensure that rhs > 0
        # (if == 0 then double count, if < 0, then violating bounds)
        ans = 0
        sq = int(sqrt(n))
        for k in range(1, n+1):   # just a while loop basically,
            rhs = n - k*(k-1)//2  # but they're slow in python
            if rhs <= 0: break
            ans += (rhs % k == 0)
        return ans
