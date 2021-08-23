# instructive. order of LRLRL doesn't matter, so we just look for
# any multiset of L's and R's that makes x = 0. This simplifies the problem
# to: longest subarray sum == s-x for s = sum(nums)
class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        ans = float('inf')
        N, s = len(nums), sum(nums)
        if x > s: return -1

        i, window = 0, 0
        for j in range(N):
            window += nums[j]
            while window > s-x and i < N:
                window -= nums[i]
                i += 1
            if window == s-x:
                win_size = j-i+1
                ans = min(ans, N - win_size)

        return -1 if ans == float('inf') else ans


# doesn't work. not monotonic.
# class Solution:
#     def minOperations(self, nums: List[int], x: int) -> int:
#         N = len(nums)
#         pre = [0] * (N+1)
#         suf = [0] * (N+1)
#         for i in range(N):
#             pre[i+1]  = pre[i]  + nums[i]
#             suf[~i-1] = suf[~i] + nums[~i]

#         def possible(g):  # O(g) ~~ O(N)
#             # 0: go higher,  1: go lower,  2: works and try lower
#             greater = False
#             print(f"g: {g} | {pre} {suf}")
#             for i in range(g+1):
#                 a, b = i, g-i
#                 s = pre[a] + suf[~b]
#                 print(a,b,s)
#                 if s == x: return 2
#                 if s > x: greater = True
#             return int(greater)

#         ans, lo, hi = -1, 0, N
#         while lo < hi:  # O(log N)
#             mid = (lo+hi) // 2
#             p = possible(mid)
#             # print(mid, p)
#             if p == 0: lo = mid+1
#             if p == 1: hi = mid
#             if p == 2:
#                 hi = mid
#                 ans = mid
#         return ans
