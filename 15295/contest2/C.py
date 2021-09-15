from heapq import heappush, heappop
intput = lambda: map(int, input().split())

def dijkstra(src):
    pq = [(0, src)]
    seen = [False] * n
    dist = [float('inf')] * n
    dist[src] = 0
    while pq:
        p, u = heappop(pq)
        for v,w in roads[u]:
            nc = dist[u] + w
            if nc < dist[v]:
                dist[v] = nc
                heappush(pq, (nc, v))
    return dist

if __name__ == '__main__':
    (n, m), (x, y) = intput(), intput()
    n += 1
    limit = [0] * n
    costs = [0] * n
    roads = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = intput()
        roads[u].append( (v, w) )
        roads[v].append( (u, w) )
    for i in range(1, n):
        limit[i], costs[i] = intput()

    dists = [None] + [dijkstra(i) for i in range(1,n)]
    roads = [[] for _ in range(n)]
    for u in range(1, n):
        for v in range(1, n):
            if u == v: continue
            if dists[u][v] <= limit[u]:
                roads[u].append( (v, costs[u]) )
    ans = dijkstra(x)[y]
    if ans == float('inf'): ans = -1
    print(ans)
