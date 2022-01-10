import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    A  = list(intput())
    ans = 0
    m = max(A)
    for x in A:
        ans = max(ans, abs(x-m))
    return ans

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
