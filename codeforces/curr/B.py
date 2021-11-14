import sys
input = sys.stdin.readline
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A = sorted(intput())
    B = sorted(intput())
    for i in range(N):
        if B[i] - A[i] not in [0,1]: return "NO"
    return "YES"

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
