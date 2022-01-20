import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def pf(x):
    for i in range(2, int(x**.5)+1):
        if x % i == 0:
            return pf(x//i) | {i}
    return {x}

def solve():
    N, = intput()
    m = min(pf(N))
    x = N//m
    return x, N-x

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( *solve() )
