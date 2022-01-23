# https://codeforces.com/problemset/problem/1578/E
# just math
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    next = 0
    ans, n = 0, 1
    h, p = intput()
    for i in range(h):
        if n <= p:
            ans += 1
        else:
            amt = n - next
            ans += amt // p
            r = amt % p
            if r == 0: next = 0
            else:
                ans += 1
                next = p - r
        n *= 2
    return ans


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
