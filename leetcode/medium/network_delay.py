class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = defaultdict(list)
        for a, b, t in times:
            graph[a-1].append((b-1,t))

        # dijkstra's
        dist = [float('inf')] * n
        seen = [False] * n
        pred = [-1] * n
        pq = [(0, k-1)]
        dist[k-1] = 0
        # pred[k-1] = k-1

        while len(pq):
            v = pq[0][1]
            heapq.heappop(pq)
            if not seen[v]:
                seen[v] = True
                for w, t in graph[v]:
                    nc = dist[v] + t
                    if dist[w] > nc:
                        dist[w] = nc
                        # pred[w] = v
                        heapq.heappush(pq, (dist[w], w))

        if any(d == float('inf') for d in dist): return -1
        return max(dist)
