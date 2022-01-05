import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, x, y = intput()
    px, py = x%2, y%2
    return int( px != py )

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
