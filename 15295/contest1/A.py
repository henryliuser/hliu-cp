intput = lambda: map(int, input().split())
N = int(input())
nums = list(intput())

ans = float('inf'), (-1,-1)
for i in range(N):
    x,y = i, (i+1)%N
    diff = abs(nums[x] - nums[y])
    if diff < ans[0]:
        ans = diff, (x,y)
a,b = ans[1]
print(a+1,b+1)
