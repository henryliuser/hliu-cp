ans = float('inf')
N, M = map(int, input().split())
price = [0] + list(map(int, input().split()))
match = [set() for _ in range(N+1)]
for _ in range(M):
    a,b = map(int, input().split())
    match[a].add(b)
    match[b].add(a)

for i in range(1,N+1):
    for j in range(i+1, N+1):
        for k in range(j+1, N+1):
            mi = i in match[j] and i in match[k]
            mj = j in match[i] and j in match[k]
            mk = k in match[i] and k in match[j]
            if mi and mj and mk:
                p = price[i] + price[j] + price[k]
                ans = min(ans, p)
print(-1 if ans == float('inf') else ans)
