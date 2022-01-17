# https://leetcode.com/contest/weekly-contest-276/problems/minimum-moves-to-reach-target-score/
class Solution:
    def minMoves(self, target: int, d: int) -> int:
        ans = 0
        while 1:
            if target == 1: return ans
            if d == 0: return ans + target - 1
            if target % 2 == 0 and d:
                target //= 2
                d -= 1
            else:
                target -= 1
            ans += 1
        return ans
