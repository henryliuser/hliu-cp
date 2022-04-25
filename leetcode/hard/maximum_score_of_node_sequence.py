# https://leetcode.com/contest/biweekly-contest-76/problems/maximum-score-of-a-node-sequence/
# actually super hard edge case screwing me lol
class Solution:
    def maximumScore(self, scores: List[int], edges: List[List[int]]) -> int:
        N = len(scores)

        adj = [[] for _ in range(N)]
        for u,v in edges:
            adj[u] += [ v ]
            adj[v] += [ u ]

        for u in range(N):
            adj[u].sort(key=lambda v : -scores[v])

        def get(adj, u, v, k):  # get the k-th thing from given adj that's not u or v
            for x in adj:
                if x in [u,v]: continue
                if k: k -= 1
                else: return x
            return -1

        ans = -1
        for u,v in edges:  # iterate on the center edge   [a -- u -- v -- b]
            x = scores[u] + scores[v]
            if len(adj[u]) < 2 or len(adj[v]) < 2: continue
            i = j = 0
            if adj[u][0] == v: i += 1
            if adj[v][0] == u: j += 1
            a = get(adj[u], u, v, 0)
            b = get(adj[v], u, v, 0)
            if a == b:
                a1 = get(adj[u], u, v, 1)
                b1 = get(adj[v], u, v, 1)
                if a1 == -1 and b1 == -1: continue
                elif a1 == -1: b = b1
                elif b1 == -1: a = a1
                else:
                    if scores[a1] >= scores[b1]:
                        a = a1
                    else:
                        b = b1
            if len( {a,b,u,v} ) < 4: continue
            ans = max(ans, x + scores[a] + scores[b])
        return ans
