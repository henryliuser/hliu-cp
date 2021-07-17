ans = 0
N, M, K = map(int, input().split())
apps = sorted(map(int, input().split()))
parts = sorted(map(int, input().split()))

i = j = 0  # i: apps, j: parts
while i < N and j < M:
    a, x = apps[i], parts[j]
    if abs(x-a) <= K:
        i, j = i+1, j+1
        ans += 1
        continue
    if a < x: i += 1
    else: j += 1

print(ans)
