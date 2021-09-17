from math import gcd
from collections import Counter
intput = lambda : map(int, input().split())

N, = intput()
A  = list(intput())
preL = [A[0]]
preR = [A[-1]]

for i in range(1, N):
    L = gcd(preL[-1], A[i])
    R = gcd(preR[-1], A[~i])
    preL.append(L)
    preR.append(R)
preR.reverse()

ans = max(preL[~1], preR[1])
for i in range(1,N-1):  # exclude i
    L = preL[i-1]
    R = preR[i+1]
    ans = max(ans, gcd(L, R))

print(ans)
