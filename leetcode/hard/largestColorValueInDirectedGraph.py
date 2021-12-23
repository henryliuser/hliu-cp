class Solution:
    def largestPathValue(self, colors: str, edges) -> int:
        N = len(colors)
        adj = [[] for _ in range(N)]
        for a, b in edges:
            adj[a].append(b)
        dp = [([0] * 26 + [-1]) for _ in range(N)]
        idx = lambda ch: ord(ch) - ord('a')

        def cycle():
            color = [1] * N
            def dfs2(u):
                color[u] = 0
                for v in adj[u]:
                    if color[v] == 0:
                        return True
                    if color[v] == 1 and dfs2(v):
                        return True
                color[u] = 2
                return False
            for i in range(N):
                if color[i] == 1:
                    if dfs2(i):
                        return True
            return False

        ans = 0
        def dfs(t, u, curr):
            nonlocal ans
            if dp[u][-1] != -1:
                for i in range(26):
                    ans = max(ans, curr[i] + dp[u][i])
                return

            dp[u][-1] = 0
            j = idx(colors[u])
            curr[j] += 1
            ans = max(ans, curr[j])
            for v in adj[u]:
                dfs(t, v, curr)
                for i in range(26):
                    dp[u][i] = max(dp[u][i], dp[v][i])
            dp[u][j] += 1
            curr[j] -= 1

        if cycle(): return -1
        for i in range(N):
            dfs(i, i, [0] * 26)
        return ans
