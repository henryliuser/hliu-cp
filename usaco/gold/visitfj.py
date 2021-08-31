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
    pq = [(0,0,0,-1)]  # (p, r, c, v)
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
    # for g in graph:
    #     print(f"{g}: {graph[g]}")
    print(dijkstra(graph))


# import sys
# dirs = ((1,0), (0,1), (-1,0), (0,-1))
#
# def dfs(r, c, curr, v):
#     print(r,c,curr,v)
#     for pd in dp:
#         print(pd)
#     if (r,c) == (N-1, N-1):
#         return curr
#     if dp[r][c][v] != -1:
#         return dp[r][c][v]
#     res = float('inf')
#     for d in dirs:
#         x, y = r+d[0], c+d[1]
#         if x < 0 or x >= N or y < 0 or y >= N:
#             continue
#         next = (v+1) % 3
#         val = curr + T
#         if next == 2: val += grid[x][y]
#         res = min(res, dfs(x, y, val, next))
#     if (r,c) == (3,2): print("HERE")
#     dp[r][c][v] = res
#     return res
#
# if __name__ == '__main__':
#     ans = float('inf')
#     # sys.stdin  = open('visitfj.in',  'r')
#     # sys.stdout = open('visitfj.out', 'w')
#     intput = lambda: map(int, input().split())
#     N, T = intput()
#     grid = [list(intput()) for _ in range(N)]
#     dp = [[[-1]*3 for _ in range(N)] for _ in range(N)]
#     print( dfs(0,0,0,-1) )



# import sys
# from heapq import heappush, heappop
# dirs = ((0,1), (1,0), (-1,0), (0,-1))
#
# def bfs():
#     seen = [[[False] * 3 for _ in range(N)] for _ in range(N)]
#     pq = [(0,0,0,-1)]  # (curr, r,c, v)
#     ans = float('inf')
#     while pq:
#         curr, r, c, v = heappop(pq)
#         if curr > limit: continue
#         if seen[r][c][v]: continue
#         seen[r][c][v] = True
#         for d in dirs:
#             x, y = r+d[0], c+d[1]
#             if x < 0 or x >= N or y < 0 or y >= N:
#                 continue
#             val = curr + T
#             if v == 2:
#                 val += grid[x][y]
#             if val > limit:
#                 continue
#             if (x,y) == (N-1, N-1):
#                 ans = min(ans, val)
#             heappush(pq, (val, x, y, (v+1)%3))
#     return ans < limit
#
#
# if __name__ == '__main__':
#     # sys.stdin  = open('visitfj.in',  'r')
#     # sys.stdout = open('visitfj.out', 'w')
#     intput = lambda: map(int, input().split())
#     N, T = intput()
#     grid = [list(intput()) for _ in range(N)]
#     bfs()
#     print(ans)
