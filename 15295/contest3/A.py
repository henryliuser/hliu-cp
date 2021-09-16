n, k = map(int, input().split())

def check(g):
    total = g+k
    adds = n-g
    return total >= adds * (adds+1) / 2

lo, hi = 0, n
while lo < hi:
    mid = (hi+lo) >> 1
    if check(mid):
        hi = mid
    else:
        lo = mid + 1

print(lo)
