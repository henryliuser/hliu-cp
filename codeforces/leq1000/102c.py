# C. Homework
from collections import Counter
S, K = input(), int(input())
count = Counter(S)
asd = sorted(count, key=lambda x: count[x])
ans = len(count)
for a in asd:
    cnt = count[a]
    if K >= cnt:
        K -= cnt
        ans -= 1
        count[a] = 0
    else:
        count[a] -= K
        K = 0
    if K == 0: break

print(ans)
for x in S:
    if count[x] == 0: continue
    count[x] -= 1
    print(x, end="")
print()
