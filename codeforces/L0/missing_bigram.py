import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A  = input().split()
    if len(A) == 1: return 'a' + A[0]
    for i in range(1, len(A)):
        if A[i-1][1] != A[i][0]:
            c = A[i-1][1] + A[i][0]
            s1 = ''.join(x[0] for x in A[:i])
            s2 = ''.join(x[1] for x in A[i:])
            return s1 + c + s2
    st = A[0][0] + (A[0][1] + A[1][0]) + A[1][1]
    return st + ''.join(x[1] for x in A[2:])

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
