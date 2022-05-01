# https://codeforces.com/contest/1673/problem/A
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

val = lambda ch : ord(ch) - ord('a') + 1

def solve():
    S = input()
    N = len(S)
    if N == 1: return ("Bob", val(S))
    if N % 2 == 0: return ("Alice", sum(val(x) for x in S))

    # odd
    if S[0] >= S[-1]:
        a = sum(map(val, S[:-1]))
        b = val( S[-1] )
    else:
        a = sum(map(val, S[1:]))
        b = val( S[0] )
    return ("Alice", abs(a-b))


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print(*solve())
