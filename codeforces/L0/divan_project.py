import sys
input = sys.stdin.readline
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A = list(enumerate(intput(), start=1))
    A.sort(key=lambda x:-x[1])
    ans = [0] * (N+1)

    c, d = 1, 0
    for i in range(N):
        j = A[i][0]
        ans[j] = c
        d += 2*A[i][1]*abs(c)
        if   c > 0: c = -c
        elif c < 0: c = 1 - c

    return d, ans


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        d,s = solve()
        print(d)
        print(*s)
