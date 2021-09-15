from heapq import heappush, heappop
import sys
sys.setrecursionlimit(1<<16)
intput = lambda: map(int, input().split())

class Node:
    idx = 0
    def __init__(self, junc, cost):
        self.idx = Node.idx
        self.junc = junc  # for debug
        self.cost = cost
        self.adj = []
        Node.idx += 1
        graph.append(self)

def dfs(u, src, remain):
    if seen[u]: return
    seen[u] = True
    # print(u, None if not src else src.junc, remain)
    if u == y:
        return src.adj.append(0)
    curr = sources[u] if not src else Node(u, 0)
    if src:
        src.adj.append(curr.idx)
        if u not in used:
            curr.adj.append(u)
            dfs(u, None, limit[u])
    else: src = curr
    for v, w in roads[u]:
        if w <= remain:
            dfs(v, src, remain-w)
    seen[u] = False

def dijkstra():
    G, pq = len(graph), [(0, 1)]
    seen = [False] * G
    dist = [float('inf')] * G
    dist[1] = 0
    while pq:
        p, u = heappop(pq)
        for v in graph[u].adj:
            nc = dist[u] + graph[v].cost
            # print(p, u, v, nc)
            if nc < dist[v]:
                dist[v] = nc
                heappush(pq, (nc, v))

    # for a,b in enumerate(dist):
    #     print(a,b)
    if dist[0] == float('inf'): return -1
    return dist[0] + costs[x]


if __name__ == '__main__':
    ans = 0
    (n, m), (x, y) = intput(), intput()
    n += 1
    graph = []
    limit = [0] * n
    costs = [0] * n
    roads = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = intput()
        roads[u].append( (v, w) )
        roads[v].append( (u, w) )
    for i in range(1, n):
        limit[i], costs[i] = intput()
    end = Node(y, 0)
    sources = [None] + [Node(i, costs[i]) for i in range(1,n)]
    used = {1}
    seen = [False] * n
    dfs(x, None, limit[x])
    for g in graph:
        print(g.idx, graph[g.idx].junc, g.cost, end=' ')
        print({g2:graph[g2].junc for g2 in g.adj})
    print( dijkstra() )
