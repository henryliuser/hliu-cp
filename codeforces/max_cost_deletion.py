# https://codeforces.com/problemset/problem/1550/B
# ab        2
# aba       2
# abab      3
# ababa     3 ababa -> abba -> aa -> ""
# ababab    4 ababab -> abbab==4
# abababa   4 abababa -> abbaba==5
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    cnt = 1
    N, A, B = intput()
    S = input()
    for i in range(1, N):
        if S[i] != S[i-1]:
            cnt += 1
    cnt = cnt//2 + 1
    if B >= 0:
        return (A+B) * N
    else:
        return A*N + B*cnt

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
