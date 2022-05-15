# https://leetcode.com/contest/biweekly-contest-78/problems/maximum-white-tiles-covered-by-a-carpet/
class Solution:
    def maximumWhiteTiles(self, tiles: List[List[int]], carpet: int) -> int:
        carpet -= 1
        tiles.sort()
        N = len(tiles)
        pre = [0] * (N+1)
        for i in range(N):
            l,r = tiles[i]
            pre[i+1] = (r-l+1) + pre[i]

        ans = 0
        for i in range(N):
            l,r = tiles[i]
            v = l + carpet
            j = bisect_right(tiles, [v,float('inf')]) - 1
            a,b = tiles[j]
            ans = max(ans, pre[j] - pre[i] + min(v,b)-a+1)

        return ans
