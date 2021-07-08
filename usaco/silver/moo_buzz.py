# with open("moobuzz.in", 'r') as f:
#     N = int(f.readline().rstrip())
N = int(input())
lo, hi = 0, int(1e18)
while lo < hi:
    mid = (lo+hi) // 2
    m3 = mid // 3
    m5 = mid // 5
    m15 = mid // 15
    if mid - m3 - m5 + m15 < N: lo = mid + 1
    else: hi = mid
print(lo)
# with open("moobuzz.out", 'w') as f:
#     f.write(str(lo) + "\n")
