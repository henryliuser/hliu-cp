ans = [False] * 2013
for i in range(1, 2014):
    for j in range(i, 2014, i):
        ans[j-1] = not ans[j-1]

print(sum(1 for x in ans if x))
