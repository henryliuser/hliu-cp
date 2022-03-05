import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A = sorted( intput() )

    sr = 0
    sb = A[0]
    i, j = 1, N-1
    while i < j:
        sr += A[j]
        sb += A[i]
        if sr > sb: return "YES"
        i, j = i+1, j-1
    return "NO"

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
