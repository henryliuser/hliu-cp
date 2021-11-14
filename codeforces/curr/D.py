import sys
from math import ceil
from bisect import bisect_left
input = sys.stdin.readline
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    i = j = k = -1
    lo, hi = 1, N
    while lo < hi:
        mid = ceil((lo + hi)/2)
        print(f"? 1 {mid}")
        sys.stdout.flush()
        x, = intput()
        if x > 0: hi = mid - 1
        else: lo = mid
    i = lo
    lo, hi = 1, N
    while lo < hi:
        mid = (lo + hi) // 2
        print(f"? {mid} {N}")
        sys.stdout.flush()
        x, = intput()
        if x > 0: lo = mid + 1
        else: hi = mid
    k = lo
    lo, hi = i+2, k-1
    while lo < hi:
        mid = (lo + hi) // 2
        left = (mid-i) * (mid-i-1) // 2
        right = (k-mid-2) * (k-mid-1) // 2
        print(f"? {i} {mid-1}")
        sys.stdout.flush()
        x, = intput()
        if left < x:
            hi = mid - 1
            continue
        print(f"? {mid} {j}")
        sys.stdout.flush()
        y, = intput()
        if right < y:
            lo = mid + 1
            continue
        if x==left and y==right:
            j = mid
            print(f"! {i} {j} {k}")
            return


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        solve()
