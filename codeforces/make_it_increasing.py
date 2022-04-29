import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    N, = intput()
    A = [*intput()]

    ans = float('inf')
    for i in range(N):
        res = 0
        B = [0] * N
        for j in range(i-1, -1, -1):
            t = B[j+1]
            q = t // A[j] + 1
            B[j] = q * A[j]
            res += q
        for j in range(i+1, N, 1):
            t = B[j-1]
            q = t // A[j] + 1
            B[j] = q * A[j]
            res += q
        ans = min(ans, res)

    print(ans)
