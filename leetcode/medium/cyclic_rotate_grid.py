class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        M, N = len(grid), len(grid[0])
        layers = min(M, N) // 2
        ans = [[-1] * N for _ in range(M)]

        def check_dir(r, c, dim, dir, start):  # return next dir
            r,c = r-start[0], c-start[1]
            r,c = r+dir[0], c+dir[1]
            if r >= dim[0]: return (0, 1)
            if c >= dim[1]: return (-1, 0)
            if r < 0: return (0, -1)
            if c < 0: return (1, 0)
            return dir

        cnt, start = 0, [0, 0]
        for L in range(layers):
            r, c = start
            dim = (M-cnt, N-cnt)
            perim = sum(2*d for d in dim) - 4
            ck = k % perim
            dir = (1, 0)
            ndir = (1, 0)
            nr, nc = r, c
            for z in range(ck):
                ndir = check_dir(nr, nc, dim, ndir, start)
                nr += ndir[0]
                nc += ndir[1]

            for z in range(perim):
                ans[nr][nc] = grid[r][c]
                dir = check_dir(r, c, dim, dir, start)
                r,c = r+dir[0], c+dir[1]
                ndir = check_dir(nr, nc, dim, ndir, start)
                nr, nc = nr+ndir[0], nc+ndir[1]

            start[0] += 1
            start[1] += 1
            cnt += 2
        return ans
