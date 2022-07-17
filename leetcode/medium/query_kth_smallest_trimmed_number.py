# https://leetcode.com/contest/weekly-contest-302/problems/query-kth-smallest-trimmed-number/
class Solution:
    def smallestTrimmedNumbers(self, nums: List[str], queries: List[List[int]]) -> List[int]:
        N = len(nums)
        M = len(nums[0])
        sortedNumsOfLen = [ [] for _ in range(M) ]
        for t in range(M):
            for i,s in enumerate(nums):
                v = int(s[~t:])
                sortedNumsOfLen[t] += [ (v,i) ]
            sortedNumsOfLen[t].sort()

        ans = []
        for k,t in queries:
            x,i = sortedNumsOfLen[t-1][k-1]
            ans += [i]
        return ans
