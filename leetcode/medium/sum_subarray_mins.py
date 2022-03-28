# https://leetcode.com/problems/sum-of-subarray-minimums/
# dp solution. refer to .cpp for stack solution
class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD = int(1e9+7)
        st = []
        N = len(arr)
        dp = [0] * N
        nse = [-1] * N
        for i in range(N-1, -1, -1):
            x = arr[i]
            while st and x < arr[st[-1]]:
                nse[st.pop()] = i
            st.append(i)
        for i in range(N):
            if nse[i] == -1:
                dp[i] = (i+1) * arr[i]
            else:
                dp[i] = (i-nse[i]) * arr[i] + dp[nse[i]]
            dp[i] %= MOD
        return sum(dp) % MOD
