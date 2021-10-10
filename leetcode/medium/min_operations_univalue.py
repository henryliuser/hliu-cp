class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        ans = 0
        flat = sorted(p for q in grid for p in q)
        y = flat[ len(flat)//2 ]
        for i in grid:
            for j in i:
                gap = j-y
                if gap % x != 0:
                    return -1
                ans += abs(gap // x)
        return ans
