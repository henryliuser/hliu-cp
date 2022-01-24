# https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/
# just bfs, sort
# sorted( bfs() ) is 4384 ms vs. res.sort() is 3044 ms
class Solution:
    def highestRankedKItems(self, grid: List[List[int]], pricing: List[int], start: List[int], k: int) -> List[List[int]]:
        sx, sy = start
        lo, hi = pricing
        M, N = len(grid), len(grid[0])
        dirs = ( (0,1), (1,0), (-1,0), (0,-1) )

        def bfs():
            res = []
            depth = 0
            seen = [[0]*N for _ in range(M)]
            seen[sx][sy] = 1
            q = deque( [(sx,sy)] )
            while q:
                sz = len(q)
                for _ in range(sz):
                    r,c = q.popleft()
                    p = grid[r][c]
                    if lo <= p <= hi:
                        res.append( (depth,p,r,c) )
                    for x,y in dirs:
                        x,y = r+x, c+y
                        if 0 <= x < M and 0 <= y < N:
                            if grid[x][y] != 0 and not seen[x][y]:
                                q.append( (x,y) )
                                seen[x][y] = 1
                depth += 1
            return res

        res = bfs()
        res.sort()
        return [x[2:] for x in res[:k]]
