N = int(input())
ans = 0
weights = sorted(map(int, input().split()))
taken = 0
while taken < 2*N - 2:
    diffs = []
    for x in range(1, len(weights)):
        d = weights[x] - weights[x-1]
        diffs.append( (d, x-1, x) )
    diffs.sort()
    d = diffs[0]
    a, b = d[1], d[2]
    taken += 2
    weights.pop(a), weights.pop(b-1)
    ans += d[0]
print(ans)
