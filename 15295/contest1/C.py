def solve():
    n, k  = map(int, input().split())
    acs = map(int, input().split())
    temps = map(int, input().split())
    ac = {}
    for a,t in zip(acs, temps):
        ac[a-1] = t

    ans = [float('inf')] * n
    curr = min(ac[x] + x for x in ac)
    for i in range(1,n):
        if i in ac:
            curr = min(curr+1, ac[i])
        else:
            curr += 1
        ans[i] = curr
    curr = float('inf')
    for i in range(n-1, -1, -1):
        if i in ac:
            curr = min(curr+1, ac[i])
        else:
            curr += 1
        ans[i] = min(ans[i], curr)

    return " ".join(map(str, ans))


Q = int(input())
for _ in range(Q):
    input()
    print(solve())
