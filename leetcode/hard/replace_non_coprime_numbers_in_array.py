# https://leetcode.com/problems/replace-non-coprime-numbers-in-array/
class Solution:
    def replaceNonCoprimes(self, A: List[int]) -> List[int]:
        ans = []
        N = len(A)
        for i in range(N):
            x = A[i]
            while ans and gcd(ans[-1], x) != 1:
                ans[-1] = lcm(ans[-1], x)
                x = ans.pop()
            ans += [x]
        return ans
