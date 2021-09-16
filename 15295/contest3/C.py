from bisect import bisect_left

N = int(input())
dp = [0] * N
beacons = []
for _ in range(N):
    a, b = map(int, input().split())
    beacons.append((a, b))
beacons.sort()

pos, pow = [], []
for b in beacons:
    pos.append(b[0])
    pow.append(b[1])

for i in range(1, N):
    x, p = pos[i], pow[i]
    target = x-p
    idx = bisect_left(pos, target) - 1
    if idx == -1: dp[i] = i
    else: dp[i] = (i-idx-1) + dp[idx]

ans = float('inf')
for i in range(N):
    ans = min(ans, dp[~i] + i)

print(ans)
