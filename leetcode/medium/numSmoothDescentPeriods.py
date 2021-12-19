# https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
class Solution:
    def getDescentPeriods(self, A: List[int]) -> int:
        A += [-1]
        N = len(A)
        c, ans = 1, 0
        for i in range(1, N):
            if A[i] + 1 == A[i-1]:
                c += 1
            else:
                ans += c * (c+1) // 2  # num substrings
                c = 1

        return ans
