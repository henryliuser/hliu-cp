# https://leetcode.com/contest/biweekly-contest-81/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        c = 0
        comp = [-1] * n
        adj = [ [] for _ in range(n) ]
        def dfs(u):
            comp[u] = c
            for v in adj[u]:
                if comp[v] == -1:
                    dfs(v)

        for u,v in edges:
            adj[u] += [v]
            adj[v] += [u]

        for u in range(n):
            if comp[u] == -1:
                dfs(u)
                c += 1

        sz = [0] * c
        for u in range(n):
            sz[ comp[u] ] += 1

        ans = ps = 0
        for p in range(c):
            ans += sz[p] * ps
            ps += sz[p]
        return ans
        
