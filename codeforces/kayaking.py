N = int(input())
ans = 0
weights = sorted(map(int, input().split()))
taken = 0
while taken < 2*N - 2:
    # print(list(range(len(weights))))
    # print(weights)
    diffs = []
    for x in range(1, len(weights)):
        d = weights[x] - weights[x-1]
        diffs.append( (d, x-1, x) )
    diffs.sort()
    # print(diffs)
    d = diffs[0]
    a, b = d[1], d[2]
    # print(a, b, d[0])
    taken += 2
    weights.pop(a), weights.pop(b-1)
    # print(taken)
    # print('-'*10)
    ans += d[0]
print(ans)
