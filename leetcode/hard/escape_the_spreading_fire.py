# https://leetcode.com/contest/biweekly-contest-77/problems/escape-the-spreading-fire/
# nice question: determine the distance from each cell to any fire, use bfs
# then binary search over the answer:
# check if some guess is possible using bfs, only going if time is less than distance
class Solution:
    def maximumMinutes(self, grid) -> int:
        M = len(grid)
        N = len(grid[0])
        dirs = [ (0,1), (1,0), (-1,0), (0,-1) ]

        def bfs1():
            # find the (manhattan + walls) dist from each grass cell to any fire cell
            q = deque()
            seen = [[0] * N for _ in range(M)]
            dist = [[inf] * N for _ in range(M)]
            for r in range(M):
                for c in range(N):
                    if grid[r][c] == 1:
                        seen[r][c] = 1
                        dist[r][c] = 0
                        q.append((r, c))

            lvl = 0
            while q:
                sz = len(q)
                for _ in range(sz):
                    i, j = q.popleft()
                    for d in dirs:
                        r = i + d[0]
                        c = j + d[1]
                        if r < 0 or r >= M or c < 0 or c >= N: continue
                        if grid[r][c] == 2: continue
                        if seen[r][c]: continue
                        seen[r][c] = 1
                        q.append((r, c))
                        dist[r][c] = lvl + 1
                lvl += 1
            return dist

        def bfs2(t, dist) -> bool:  # possible if wait t seconds?
            q = deque([(0, 0)])
            seen = [[0] * N for _ in range(M)]

            while q:
                sz = len(q)
                for _ in range(sz):
                    i, j = q.popleft()
                    for d in dirs:
                        r = i + d[0]
                        c = j + d[1]
                        if r < 0 or r >= M or c < 0 or c >= N: continue
                        if grid[r][c] == 2: continue
                        if seen[r][c]: continue
                        if (r, c) == (M-1, N-1):
                            if dist[r][c] >= t+1:  # if dist[r][c] == t+1, made it just in time
                                return True
                        if dist[r][c] <= t+1: continue  # would have fire on it right after we go there
                        seen[r][c] = 1
                        q.append((r, c))
                t += 1

            return False

        dist = bfs1()
        l, r = -1, int(1e9)
        while l < r:
            m = (l + r + 1) // 2
            if bfs2(m, dist):
                l = m
            else:
                r = m - 1
        return l
