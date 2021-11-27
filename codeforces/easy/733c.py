t = int(input())
def solve():
    n = int(input())
    mine = sorted(map(int, input().split()))
    ilya = sorted(map(int, input().split()))
    preM, preI = [0], [0]
    for x in range(n):
        preM.append(mine[~x] + preM[x])
        preI.append(ilya[x] + preI[x])
    preM = list(reversed(preM))
    preM.pop(-1)

    def check(r):
        leng = n+r
        top = leng - leng//4
        my_lap = max(0, top-r)
        my_score = 100*r + (preM[-my_lap] if my_lap > 0 else 0)
        il_score = preI[-1] - preI[max(0, n-top)]
        return my_score >= il_score

    lo, hi = 0, 3*n
    while lo < hi:
        mid = (lo+hi) // 2
        if check(mid): hi = mid
        else: lo = mid + 1
    return lo

for _ in range(t):
    print(solve())
