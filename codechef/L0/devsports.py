import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    Z, Y, A, B, C = intput()
    return "YES" if (Z-Y) >= sum((A, B, C)) else "NO"

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
