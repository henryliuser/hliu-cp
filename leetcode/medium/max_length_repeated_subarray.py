# O(N log N) rabin karp binary search
class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        M, N = len(nums1), len(nums2)
        MOD = int(1e9+7)
        BX = 7

        def rabin_karp(src, m, b, q):
            h, d, t = (1<<(b*m-b)) % q, 1 << b, 0
            for i in range(m):
                t = (d*t + src[i]) % q
            hashes = {t}
            for i in range(len(src) - m):
                t = (d*(t-src[i]*h) + src[i+m]) % q
                hashes.add(t)
            return hashes

        lo, hi = 0, min(M,N)
        while lo < hi:
            mid = ceil((lo+hi) / 2)
            rk1 = rabin_karp(nums1, mid, BX, MOD)
            rk2 = rabin_karp(nums2, mid, BX, MOD)
            if len(rk1 & rk2) > 0:
                lo = mid
            else:
                hi = mid-1
        return lo


# O(MN) dp
class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        ans = 0
        M, N = len(nums1), len(nums2)
        dp = [[0] * (N+1) for _ in range(2)]
        # dp[i][j] = LCSubstring between nums1[:i] & nums2[:j]
        # that MUST INCLUDE nums1[i] and nums2[j]
        for i in range(1, M+1):
            t = i % 2
            for j in range(1, N+1):
                if nums1[i-1] == nums2[j-1]:
                    dp[t][j] = 1 + dp[not t][j-1]
                    ans = max(ans, dp[t][j])
                else:
                    dp[t][j] = 0

        return ans
