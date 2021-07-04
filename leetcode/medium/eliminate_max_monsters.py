class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        ans = 0
        pq = sorted(dist[x] / speed[x] for x in range(len(dist)))
        for c, x in enumerate(pq):
            if c < x: ans += 1
            else: break
        return ans
