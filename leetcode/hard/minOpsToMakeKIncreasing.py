# https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/
class Solution:
    def kIncreasing(self, arr: List[int], k: int) -> int:
        L = [arr[i::k] for i in range(k)]

        def lis(A):
            dp = []
            for x in A:
                i = bisect_right(dp, x)
                if i == len(dp): dp.append(x)
                else: dp[i] = x
            return len(dp)

        return sum(len(x) - lis(x) for x in L)
