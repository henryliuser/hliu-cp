def solve():
    N = int(input())
    d = {}
    ans = 0
    nums = list(map(int, input().split()))
    for x in range(N):
        ajmj = nums[x]-x
        if ajmj in d:
            d[ajmj] += 1
            ans += d[ajmj]
        else: d[ajmj] = 0
    print(ans)
        
for _ in range(int(input())):
    solve()
