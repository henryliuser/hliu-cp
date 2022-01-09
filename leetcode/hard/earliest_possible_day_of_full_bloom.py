# https://leetcode.com/contest/weekly-contest-275/problems/earliest-possible-day-of-full-bloom/
class Solution:
    def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
        N = len(plantTime)
        k = lambda i : (-growTime[i], plantTime[i])
        order = sorted(range(N), key=k)

        ans = cur = 0
        for i in order:
            pt = plantTime[i]
            gt = growTime[i]
            ans = max(ans, cur+pt+gt)
            cur = cur+pt
        return ans
