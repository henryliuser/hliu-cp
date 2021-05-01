class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        n, m = len(heights), len(heights[0])
        pacific, atlantic = set(), set()
        def dfs(r, c, ocean):
            if (r,c) in ocean: return
            ocean.add( (r,c) )
            val = heights[r][c]
            dirs = [(0,1), (0,-1), (1,0), (-1,0)]
            for d in dirs:
                nr, nc = r+d[0], c+d[1]
                if 0 <= nr < n and 0 <= nc < m and heights[nr][nc] >= val:
                    dfs(nr, nc, ocean)

        for i in range(n):
            dfs(i, 0,   pacific)
            dfs(i, m-1, atlantic)

        for i in range(m):
            dfs(0, i,   pacific)
            dfs(n-1, i, atlantic)

        return list(pacific & atlantic)
