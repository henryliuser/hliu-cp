import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    ans = 0
    N, = intput()
    A  = list(intput())
    for b in range(32):
        b = 1 << b
        if sum(not not x&b for x in A) > 1:
            ans |= b
    return ans

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
