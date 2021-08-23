# quite instructive question.
# illustrates DP forward/backward then merge technique
class Solution:
    def candy(self, A: List[int]) -> int:
        N = len(A)
        dp = [1] * N
        for i in range(1,N):
            if A[i] > A[i-1]:
                dp[i] = 1 + dp[i-1]
        for i in range(N-2, -1, -1):
            if A[i] > A[i+1]:
                dp[i] = max(dp[i], 1 + dp[i+1])
        return sum(dp)
