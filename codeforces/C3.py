import sys
input = sys.stdin.readline
intput = lambda : map(int, input().split())

def solve():
    N, M = intput()
    seg = [tuple(intput()) for _ in range(M)]
    seg.sort(key=lambda x: x[1]-x[0])
    return seg

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
