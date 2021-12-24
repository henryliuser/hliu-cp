class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        adj = [[] for _ in range(n)]
        for a,b in edges:
            adj[a] += [b]
            adj[b] += [a]

        t = 0
        m = sum(1 for a in hasApple if a)
        def dfs(u, p):
            nonlocal t
            app = False
            for v in adj[u]:
                if v == p: continue
                if dfs(v, u):
                    t += 2
                    app = True
            return app or hasApple[u]

        dfs(0, -1)
        return t
            
