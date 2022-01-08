# this is actually n^3. there are n sources and can be up to n^2 edges.
# for a true n^2, decompose into SCC's and convert to dag. Then traverse.
class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:

        def reaches(i, j):
            x1,y1,r1 = bombs[i]
            x2,y2,r2 = bombs[j]
            dx = x2-x1
            dy = y2-y1
            dist = dx*dx + dy*dy
            return r1*r1 >= dist

        N = len(bombs)
        adj = [[] for _ in range(N)]

        for i in range(N):
            for j in range(i+1, N):
                if i == j: continue
                if reaches(i, j): adj[i] += [j]
                if reaches(j, i): adj[j] += [i]

        ans = 0
        for i in range(N):
            seen = [False] * N
            q = deque([i])
            seen[i] = True
            while q:
                u = q.popleft()
                for v in adj[u]:
                    if seen[v]: continue
                    seen[v] = True
                    q.append(v)
            res = sum(seen)
            ans = max(ans, res)

        return ans
