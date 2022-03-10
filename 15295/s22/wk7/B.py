# https://codeforces.com/problemset/problem/1236/B
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
Q = int(1e9+7)
if __name__ == '__main__':
    N, M = intput()
    p = pow(2, M, Q)
    print(pow(p-1, N, Q))
