import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    b = sorted(intput())
    a = [b[0], b[1], -1]
    if a[0] + a[1] == b[2]:
        a[2] = b[3]
    else:
        a[2] = b[2]
    return a


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( *solve() )
