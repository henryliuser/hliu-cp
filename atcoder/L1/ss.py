# https://atcoder.jp/contests/abc066/tasks/abc066_b
# KMP definition
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def kmp(S):
    N = len(S)
    pi = [0] * N
    for i in range(1, N):
        j = pi[i-1]
        while j and S[i] != S[j]:
            j = pi[j-1]
        if S[i] == S[j]:
            j += 1
        pi[i] = j
    return pi

if __name__ == '__main__':
    pi = kmp( input() )
    for i in range(len(pi)-3, -1, -2):
        if pi[i] == (i+1) // 2:
            break
    print(i+1)
