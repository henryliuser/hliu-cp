t = int(input())
for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    d = {}
    for x in range(n):
        if nums[x] in d: d[nums[x]][0] += 1
        else: d[nums[x]] = [1, x]
        if x >= 2 and len(d) > 1:
            for y in d:
                if d[y][0] == 1:
                    print(d[y][1]+1)
                    break
            break
