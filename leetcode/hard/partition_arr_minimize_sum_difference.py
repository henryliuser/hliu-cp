# Meet in the middle (divide & conquer)
# 2^n * log(2^n)
class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        S = sum(nums)
        ans = float('inf')
        n = len(nums) // 2
        left  = [[] for _ in range(n+1)]
        right = [[] for _ in range(n+1)]
        left[0], right[0] = [0], [0]

        def dfs(i, sz, s, p, offset, took):
            if took: p[sz].append(s)
            if i >= n: return
            dfs(i+1, sz, s, p, offset, False)
            dfs(i+1, sz+1, s+nums[offset+i], p, offset, True)

        dfs(0, 0, 0, left,  0, False)
        dfs(0, 0, 0, right, n, False)

        T = S // 2
        for r in right: r.sort()
        for sz, l in enumerate(left):
            v = right[~sz]
            for q in l:
                i = min(len(v)-1, bisect_left(v, T - q))
                k = q + v[i]
                o = S - k
                ans = min(ans, abs(o-k))

        return ans


# O(2^(2n)) brute force, tle
class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        ans = float("inf")
        n = len(nums) // 2
        t = sum(nums)
        def dfs(i, q, s):
            nonlocal ans
            if i >= n*2: return
            if q == n:
                o = t - s
                ans = min(ans, abs(o-s))
                return

            dfs(i+1, q, s)
            dfs(i+1, q+1, s+nums[i])

        dfs(0, 0, 0)
        return ans
