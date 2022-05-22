# https://atcoder.jp/contests/abc252/tasks/abc252_d
# just dp
import sys
input = lambda: sys.stdin.readline().strip()
intput = lambda: map(int, input().split())

def solve():
    N, = intput()
    A = [*intput()]
    cnt = [0] * int(2e5+5)
    for x in A: cnt[x] += 1
    A = sorted(set(A))

    p = dp = ans = 0
    for i,x in enum(A):
        c = cnt[x]
        ans += dp * c
        dp += p * c
        p += c
    return ans

if __name__ == '__main__':
    print( solve() )
