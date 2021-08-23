# instructive. order of LRLRL doesn't matter, so we just look for
# any multiset of L's and R's that makes x = 0. This simplifies the problem
# to: longest subarray sum == s-x for s = sum(nums)
# so we can sliding window O(N).
class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        ans = -1
        N, s = len(nums), sum(nums)
        if x > s: return -1

        i, window = 0, 0
        for j in range(N):
            window += nums[j]
            while window > s-x and i < N:
                window -= nums[i]
                i += 1
            if window == s-x:
                ans = max(ans, j-i+1)

        if ans == -1: return -1
        return N - ans


# hashmap solution, slower
class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        sufH = {0:0}
        pre = suf = 0
        ans, N = float('inf'), len(nums)

        for i in range(N):
            suf += nums[~i]
            sufH[suf] = i+1
        if x in sufH: ans = sufH[x]
        for i in range(N):
            pre += nums[i]
            if x-pre in sufH and N-sufH[x-pre] > i:
                ans = min(ans, i+1 + sufH[x-pre])

        if ans == float('inf'): return -1
        return ans
            
