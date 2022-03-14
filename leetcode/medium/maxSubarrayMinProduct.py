# https://leetcode.com/problems/maximum-subarray-min-product/
class Solution:
    def maxSumMinProduct(self, A: List[int]) -> int:
        N = len(A)

        pre = [0] + A  # prefix sum
        for i in range(1, N+1):
            pre[i] += pre[i-1]

        def mono(L, loop, st=[]):
            for i in loop:
                while st and A[i] < A[st[-1]]:
                    L[st.pop()] = i
                st.append(i)

        # next/prev lesser element
        nle, ple = [N]*N, [-1]*N
        mono( nle, range(N) )
        mono( ple, range(N-1,-1,-1) )

        ans = 0
        for i in range(N):
            L, R = ple[i], nle[i]  # subarray bounds
            s = pre[R] - pre[L+1]  # subarray sum
            x = A[i] * s           # min product
            ans = max(ans, x)

        return ans % int(1e9+7)
