# https://atcoder.jp/contests/abc230/tasks/abc230_b
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    S = input()
    if S in ["x", "xx", "oxx", "xxo"]:
        return "Yes"
    i = S.find('o')
    T = "oxx"
    c = 0
    for j in range(i, len(S)):
        if S[j] != T[c]:
            return "No"
        c = (c + 1) % 3
    c = 2
    for j in range(i-1, -1, -1):
        if S[j] != T[c]:
            return "No"
        c = (c - 1) % 3
    return "Yes"

if __name__ == '__main__':
    print( solve() )
