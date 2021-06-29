N, M = map(int, input().split())
graph = [[] for _ in range(N)]
for _ in range(M):
    x, y = map(int, input().split())
    x,y = x-1,y-1
    graph[x].append(y)

dp = [-1] * N
def longestPath(i):
    if dp[i] != -1:
        return dp[i]
    if len(graph[i]) == 0: dp[i] = 0
    for j in graph[i]:
        dp[i] = max(dp[i], 1 + longestPath(j))
    return dp[i]

ans = 0
for x in range(len(graph)):
    ans = max(ans, longestPath(x))

print(ans)
