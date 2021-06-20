class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:

        M, N = len(grid1), len(grid1[0])
        seen = [[False] * N for _ in range(M)]
        dirs = ((1,0), (-1,0), (0,1), (0,-1))
        sub = True
        def dfs(r, c):
            nonlocal sub
            if seen[r][c]: return
            seen[r][c] = True
            if grid1[r][c] != 1: sub = False
            for d in dirs:
                x, y = r+d[0], c+d[1]
                if (x >= 0 and x < M and y >= 0 and y < N):
                    if not seen[x][y] and grid2[x][y] == 1:
                        dfs(x, y)

        ans = 0
        for x in range(M):
            for y in range(N):
                if (not seen[x][y]) and grid2[x][y] == 1:
                    # print(x,y)
                    sub = True
                    dfs(x, y)
                    ans += int(sub)
        return ans
                    
