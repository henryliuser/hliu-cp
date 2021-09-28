from collections import defaultdict
intput = lambda : map(int, input().split())

def solve():
    N = int(input())
    arr = list( intput() )
    def left_shift(a, k):
        l, b = len(a), list(a)
        k = l - k
        a[:k] = b[l-k:]
        a[k:] = b[:l-k]
        return a
    out = sorted(arr)
    shifts = []
    for i,o in enumerate(out):
        right = arr.index(o, i)
        if right == i: continue
        shamt = right - i
        shifts.append(f"{i+1} {right+1} {shamt}")
        seg = arr[i:right+1]
        lsh = left_shift(seg, shamt)
        arr[i:right+1] = lsh
    print(len(shifts))
    for sh in shifts:
        print(sh)

T = int(input())
for _ in range(T):
    solve()
