N = int(input())

lo, hi = 1, int(1e9)
while lo < hi:
    mid = (lo + hi) // 2
    if mid * (mid+1) / 2 >= N:
        hi = mid
    else: lo = mid + 1
print(lo)
