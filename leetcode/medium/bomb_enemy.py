class Solution:
    def maxKilledEnemies(self, grid: List[List[str]]) -> int:
        ans = 0
        M, N = len(grid), len(grid[0])
        cols = [[0] * (N+1) for _ in range(M+1)]
        rows = [[0] * (N+1) for _ in range(M+1)]

        for r in range(1, M+1):
            for c in range(1, N+1):
                g = grid[r-1][c-1]
                col = cols[r-1][c]
                row = rows[r][c-1]
                if g == 'E':
                    col += 1
                    row += 1
                if g == 'W':
                    col = row = 0
                cols[r][c] = col
                rows[r][c] = row

        cols2 = [[0] * (N+1) for _ in range(M+1)]
        rows2 = [[0] * (N+1) for _ in range(M+1)]
        for r in range(M-1, -1, -1):
            for c in range(N-1, -1, -1):
                g = grid[r][c]
                col = cols2[r+1][c]
                row = rows2[r][c+1]
                if g == 'E':
                    col += 1
                    row += 1
                if g == 'W':
                    col = row = 0
                cols2[r][c] = col
                rows2[r][c] = row
                if g == '0':
                    amt = col + row + cols[r+1][c+1] + rows[r+1][c+1]
                    ans = max(ans, amt)

        return ans
