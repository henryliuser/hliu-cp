class Solution:
    def minDifference(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        ans = []
        N = len(nums)
        dp = [[0] * 101 for _ in range(N+1)]

        for n in range(1, N+1):
            for x in range(1, 101):
                dp[n][x] = dp[n-1][x]
            dp[n][nums[n-1]] += 1

        for q in queries:
            L, R = q[0], q[1] + 1
            x, y = dp[L], dp[R]
            new_nums = [i for i in range(1, 101) if x[i] != y[i]]
            new_count = len(new_nums)
            min_diff = float('inf')
            if new_count <= 1: min_diff = abs(nums[R-1], nums[L])
            for n in range(1, new_count):
                diff = new_nums[n] - new_nums[n-1]
                min_diff = min(min_diff, diff)
            if min_diff == 0: min_diff = -1
            ans.append(min_diff)

        return ans


        # Brute Force
        # ans = []
        # for q in queries:
        #     s = sorted(set(nums[q[0]:q[1]+1]))
        #     l = len(s)
        #     if l == 1:
        #         ans.append(-1)
        #     else:
        #         mini = 101
        #         for x in range(1, l):
        #             mini = min(mini, abs(s[x]-s[x-1]))
        #         ans.append(mini)
        # return ans
