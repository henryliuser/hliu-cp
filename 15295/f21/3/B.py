from math import ceil
intput = lambda: map(int, input().split())
n, S = intput()
cost = list(intput())

def check(k):
    global T
    newcost = [cost[i] + (i+1)*k for i in range(n)]
    newcost.sort()
    # print(newcost)
    s = sum(newcost[c] for c in range(k))
    if s <= S:
        return True, s
    return False, None

T = S
lo, hi = 0, n
while lo < hi:
    mid = ceil((hi+lo) / 2)
    # print(mid)
    ch = check(mid)
    if ch[0]:
        lo = mid
    else:
        hi = mid - 1

print(lo, check(lo)[1])
