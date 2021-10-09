from heapq import heappush, heappop
intput = lambda : map(int, input().split())
    
def solve():
    n, m = intput()
    graph = [[] for _ in range(n+1)]
    for _ in range(m):
        a, b, w = intput()
        graph[a].append( (b,w) )
        graph[b].append( (a,w) )

    pq = [(1,1)]
    dist = [float('inf') for _ in range(n+1)]
    seen = [False for _ in range(n+1)]
    prev = [-1 for _ in range(n+1)]
    dist[1] = 0
    prev[1] = -1

    while pq:
        p, u = heappop(pq)
        if seen[u]: continue
        seen[u] = True
        for v, w in graph[u]:
            nc = w + dist[u]
            if nc < dist[v]:
                dist[v] = nc
                heappush(pq, (nc, v))
                prev[v] = u

    if dist[n] == float('inf'): print(-1)
    else:
        path, i = [], n
        while i != -1:
            path.append(i)
            i = prev[i]
        print(" ".join(map(str,reversed(path))))

s = solve()
if s == -1: print(s)
