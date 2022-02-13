# https://leetcode.com/contest/weekly-contest-280/problems/removing-minimum-number-of-magic-beans/
class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        beans.sort()
        N = len(beans)
        sfx = [0] * (N+1)
        for i in range(N-1, -1, -1):
            sfx[i] = sfx[i+1] + beans[i]

        ans, pre = 1e18, 0
        for i,x in enumerate(beans):
            y = sfx[i+1] - x * (N-i-1)
            ans = min(ans, y + pre)
            pre += x
        return ans
