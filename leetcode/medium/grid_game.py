class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        N = len(grid[0])
        ans, down = float('inf'), -1
        ps = [[0], [0]]
        for i in range(N):
            ps[0].append(grid[0][i] + ps[0][-1])
            ps[1].append(grid[1][i] + ps[1][-1])
        for i in range(N):
            v = max(ps[1][i], ps[0][-1] - ps[0][i+1])
            if v < ans:
                ans, down = v, i
        return ans
