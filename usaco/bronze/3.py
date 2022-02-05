# 
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    H = list(intput())

    ans = float('inf')
    lo, hi = -1, min(H)
    while lo < hi:
        A = H[:]
        mid = (lo+hi+1) // 2
        if mid == -1:
            hi = -1
            break

        ops = 0
        for i in range(N-1):
            h = A[i]
            dx = h - mid
            if dx > 0:
                A[i]   -= dx
                A[i+1] -= dx
                ops += 2 * dx

        sq = set(A)
        uq = len(sq)
        ok = not any(h < mid for h in sq)
        if ok and (uq == 1 or (N%2 and uq == 2)):
            if uq == 1: ans = min(ans, ops)
            lo = mid
        else:
            hi = mid-1

    if lo == -1: return -1
    else: return ans

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
