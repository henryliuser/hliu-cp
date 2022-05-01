# https://codeforces.com/contest/1673/problem/B
# prefix sum. for every (adjacent) pair of equal chars,
# consider the frequencies of all characters in the substring
# between them. If there's any with frequency 0, return no
import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")
intput = lambda : map(int, input().split())

A = ord('a')
val = lambda ch : ord(ch) - A

def solve():
    S = input()
    N = len(S)
    has = [0]*26
    for x in S:
        has[ val(x) ] = 1

    prev = [-1]*26
    cnt = [ [0]*26 for _ in range(N+1) ]

    for i in range(1, N+1):
        x = S[i-1]
        j = val(x)
        p = prev[j]
        for k in range(26):
            cnt[i][k] += cnt[i-1][k] + (k==j)
        if p != -1:
            c = cnt[p-1]
            for k in range(26):
                if k == j: continue
                if not has[k]: continue
                if cnt[i][k] - c[k] == 0:
                    return "NO"
        prev[j] = i

    return "YES"


if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print(solve())
