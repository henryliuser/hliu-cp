import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A  = list(intput())

    ans = 0
    for i in range(N):
        ans = max(ans, A[i] - i - 1)
    return ans

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
