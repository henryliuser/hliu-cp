# https://atcoder.jp/contests/abc238/tasks/abc238_c
# f(1) = 1, f(9) = 9, f(15) = 5, f(205) = 105
# f(x) = x - 10^p + 1 where p = len(x)
import sys
Q = 998244353
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    N = input()
    L = len(N)
    con = lambda  x  : x*(x+1)//2 % Q
    f   = lambda x,p : x - pow(10,p,Q) + 1

    ans = 0
    N = int(N)
    for p in range(L-1):
        x = pow(10, p+1, Q)-1
        ans += con(f(x,p))
        ans %= Q
    ans += con(f(N, L-1))
    print(ans % Q)
