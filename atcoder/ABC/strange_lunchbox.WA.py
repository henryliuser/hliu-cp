from collections import Counter
intput = lambda : map(int, input().split())
N = int(input())
X, Y = intput()

boxes = []
for _ in range(N):
    a, b = intput()
    boxes.append( (a,b) )

# print(boxes)
def check(x):
    a, b = 0, 0
    c = Counter(boxes)
    for _ in range(x):
        o = None
        maxVal = 0
        for p,q in c:
            if (a+p) >= X and (b+q) >= Y: return True
            val = (X-a)*p + (Y-b)*q
            if val > maxVal:
                o = (p,q)
                maxVal = val
        a, b = a+o[0], b+o[1]
        c[o] -= 1
        if c[o] == 0:
            del c[0]
    return False

lo, hi = 0, N
ans = -1
while lo < hi:
    mid = (lo + hi) // 2
    # print(lo,mid,hi)
    if check(mid):
        ans = hi = mid
    else:
        lo = mid + 1

print(ans)
