from random import randint as rng
# N = rng(5, 23)
# A = sorted( rng(0,10) for _ in range(N) )
N = 5
A = [1,1,1,1,1]

def f(x, g):
    B = A[:]
    B[0] -= x
    for i in range(min(g-x, N-1)):
        B[~i] = B[0]
    # print(B)
    return sum(B)

def check(g):
    lo, hi = 0, g
    while lo < hi:
        mid = (lo+hi+1) // 2
        a = f(mid, g)
        b = f(mid+1, g) if mid+1 != g else a
        if a == b: return a
        if a < b: hi = mid-1
        else: lo = mid
    return f(lo, g)

print(A)
for g in range(10):
    b = check(g)
    print(g, b)
        # B = f(i,g)
        # print(i, sum(B), B)
