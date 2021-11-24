import sys
input = sys.stdin.readline
intput = lambda : map(int, input().split())

def solve():
    N, M = intput()
    return min(N, M)

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
