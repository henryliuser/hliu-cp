# pair = count = 0
# asd = (['r'] * 5) + (['b'] * 6)
# for x in range(11):
#     for y in range(x+1, 11):
#         if asd[x] == asd[y]: pair += 1
#         count += 1
# print(pair, count)
# print(pair/count)
#
#
dp = [0] * 100
dp[1] = 1
dp[2] = 1
for i in range(3, 100):
    dp[i] = dp[i-2] + 2

print(dp)
