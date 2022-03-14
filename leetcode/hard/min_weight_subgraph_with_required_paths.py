# https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/
class Solution:
    def minimumWeight(self, N: int, edges: List[List[int]], src1: int, src2: int, dest: int) -> int:

        def dijkstra(src, g):
            dist = [inf] * N
            dist[src] = 0
            pq = [(0,src)]
            while pq:
                p,u = heappop(pq)
                if p != dist[u]: continue
                for v,c in g[u]:
                    nc = c + p
                    if nc < dist[v]:
                        dist[v] = nc
                        heappush(pq, (nc, v))
            return dist

        adj = [[] for _ in range(N)]
        inv = [[] for _ in range(N)]
        for u,v,c in edges:
            adj[u] += [(v,c)]
            inv[v] += [(u,c)]

        dN = dijkstra(dest, inv)
        d1 = dijkstra(src1, adj)
        d2 = dijkstra(src2, adj)

        ans = inf
        for v in range(N):
            x = d1[v] + d2[v] + dN[v]
            ans = min(ans, x)
        return ans if ans != inf else -1
