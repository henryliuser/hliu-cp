class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        ans = 0
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        N = len(envelopes)
        dp = [[0,0] for _ in range(N)]
        for e in envelopes:
            lo, hi = 0, ans
            while lo < hi:
                mid = (lo+hi) // 2
                em = dp[mid]
                if em[0] < e[0] and em[1] < e[1]:
                    lo = mid+1
                else: hi = mid
            dp[lo] = e
            if lo == ans: ans += 1
        return ans


# class Solution:
#     def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
#         ans = 1
#         envelopes.sort()
#         N = len(envelopes)
#         dp = [1] * N
#         for i in range(1, N):
#             mx = 0
#             a = envelopes[i]
#             for j in range(i):
#                 b = envelopes[j]
#                 if b[0] < a[0] and b[1] < a[1]:
#                     mx = max(mx, dp[j])
#             dp[i] = mx + 1
#             ans = max(ans, dp[i])

#         return ans


        
