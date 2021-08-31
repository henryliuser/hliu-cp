import sys
from heapq import heappop, heappush
from collections import defaultdict

dirs = ((1,0), (0,1), (-1,0), (0,-1))
def build_graph():
    graph = defaultdict(list)
    def dfs(r,c,v):
        if len(graph[(r,c,v)]) != 0: return
        next = (v + 1) % 3
        for d in dirs:
            x, y = r+d[0], c+d[1]
            if x >= 0 and x < N and y >= 0 and y < N:
                edge = T if next != 2 else T + grid[x][y]
                graph[(r,c,v)].append((x, y, next, edge))
                dfs(x,y,next)
    dfs(0,0,-1)
    return graph

def dijkstra(graph):
    pq = [(0,0,0,-1)]  # (priority, row, column, cycle)
    seen = set()
    dist = defaultdict(lambda: float('inf'))
    dist[(0,0,-1)] = 0
    while pq:
        p, r, c, v = heappop(pq)
        if (r,c,v) in seen: continue
        seen.add((r,c,v))
        for x,y,n,t in graph[(r,c,v)]:
            nc = dist[(r,c,v)] + t
            if nc < dist[(x,y,n)]:
                dist[(x,y,n)] = nc
                heappush(pq, (nc,x,y,n) )
    return min(dist[(N-1, N-1, i)] for i in range(3))


if __name__ == '__main__':
    sys.setrecursionlimit(1<<28)
    sys.stdin  = open('visitfj.in',  'r')
    sys.stdout = open('visitfj.out', 'w')
    intput = lambda: map(int, input().split())
    N, T = intput()
    grid = [list(intput()) for _ in range(N)]
    graph = build_graph()
    print(dijkstra(graph))
