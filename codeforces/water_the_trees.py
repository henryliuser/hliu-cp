import sys
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A = [*intput()]
    mx = max(A)

    def check(g, m):
        B = A[:]
        one, two = (g+1)//2, g//2
        for i in range(N):
            dx = m - B[i]
            q = min(two, dx // 2)
            B[i] += q * 2
            two -= q
            if not two: break
        for i in range(N):
            dx = m - B[i]
            q = min(one, dx)
            one -= q
            B[i] += q
            if B[i] != m: return False
        return True

    l, r = 0, 1<<60
    while l < r:
        g = (l+r)//2
        if check(g, mx) or check(g, mx+1):
            r = g
        else:
            l = g+1
    return l

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
