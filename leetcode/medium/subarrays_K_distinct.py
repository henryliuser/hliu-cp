class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        N = len(nums)
        # the lesson here is to use combinatorics
        # some problems are a lot easier to count
        # break it into easier counting problems
        # then solve with discrete math.
        def subarrays_LEQ_K_distinct(x):
            lo, ans = 0, 0
            curr = defaultdict(int)
            for hi in range(N):
                curr[nums[hi]] += 1
                while len(curr) > x:
                    ans += hi - lo
                    curr[nums[lo]] -= 1
                    if curr[nums[lo]] == 0:
                        curr.pop(nums[lo])
                    lo += 1
            while lo < N:
                ans += N-lo
                lo += 1
            return ans
        a = subarrays_LEQ_K_distinct(k)
        b = subarrays_LEQ_K_distinct(k-1)
        return a-b
