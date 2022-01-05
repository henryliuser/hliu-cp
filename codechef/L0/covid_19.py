import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, M = intput()
    r = (N+1) // 2
    c = (M+1) // 2
    return r * c

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
