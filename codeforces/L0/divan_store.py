import sys
input = sys.stdin.readline
intput = lambda : map(int, input().split())

def solve():
    ans = 0
    n, l, r, k = intput()
    A = list(intput())
    B = sorted( (x for x in A if l <= x <= r) )
    for x in B:
        if k >= x:
            ans += 1
            k -= x
        if k <= 0:
            break
    return ans

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
