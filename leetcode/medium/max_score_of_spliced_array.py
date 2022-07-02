# https://leetcode.com/contest/weekly-contest-299/problems/maximum-score-of-spliced-array/
class Solution:
    def maximumsSplicedArray(self, A: List[int], B: List[int]) -> int:
        ans = 0
        N = len(A)
        for _ in "hi":
            s = sum(A)
            dx = [ B[i]-A[i] for i in range(N) ]

            cur = mn = 0
            for x in dx:
                mn = min(mn, cur)
                cur += x
                ans = max(ans, s+cur-mn)
            A,B = B,A

        return ans
