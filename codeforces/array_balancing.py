import sys
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    ans = 0
    N, = intput()
    A = [*intput()]
    B = [*intput()]
    for i in range(N):
        if A[i] > B[i]:
            A[i], B[i] = B[i], A[i]
        if i:
            ans += abs(A[i] - A[i-1])
            ans += abs(B[i] - B[i-1])
    return ans

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
