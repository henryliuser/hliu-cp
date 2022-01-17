# https://leetcode.com/problems/maximum-subarray-min-product/
class Solution:
    def maxSumMinProduct(self, nums: List[int]) -> int:
        N = len(nums)
        nle, ple = [N]*N, [-1]*N
        # next/prev lesser element
        pre = [0] + nums
        for i in range(1, N+1):
            pre[i] += pre[i-1]

        def mono(L, rev, st=[]):
            r = range(N)
            if rev: r = reversed(r)
            for i in r:
                while st and nums[i] < nums[st[-1]]:
                    L[st.pop()] = i
                st.append(i)

        ans = 0
        mono(nle, 0), mono(ple, 1)
        for i in range(N):
            L, R = ple[i], nle[i]
            s = pre[R] - pre[L+1]
            x = nums[i] * s
            ans = max(ans, x)
        return ans % int(1e9+7)
