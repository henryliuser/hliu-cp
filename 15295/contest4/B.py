intput = lambda : map(int, input().split())
n, m, k = intput()
A = list( intput() )
L = n-m+1
pre = [0]
for x in A:
    pre.append(x + pre[-1])
S = [pre[i+m]-pre[i] for i in range(L)]
dp = [[0] * (k+1) for _ in range(L+1)]

for j in range(1,k+1):
    for i in range(1,L+1):
        dp[i][j] = max(dp[i-1][j], S[i-1])
        if i < m: continue
        dp[i][j] = max(dp[i][j], S[i-1] + dp[i-m][j-1])

# for d in dp:
#     print(d)

print( dp[-1][-1] )
