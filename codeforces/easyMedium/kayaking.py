N = int(input())
ans = 1e9
weights = sorted(map(int, input().split()))
for x in range(2*N):  # brute force on singles
    for y in range(x+1, 2*N):
        rest = [weights[z] for z in range(2*N) if (z != x and z != y)]
        curr = sum(rest[z]-rest[z-1] for z in range(1, len(rest), 2))
        ans = min(ans, curr)
print(ans)
