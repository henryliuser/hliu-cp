# https://atcoder.jp/contests/abc250/submissions/31773592
import sys
input = lambda: sys.stdin.readline().strip()
intput = lambda: map(int, input().split())

if __name__ == '__main__':
    N, Q = intput()
    A = [i for i in range(N)]
    idx = [i for i in range(N)]
    for _ in range(Q):
        x = [*intput()][0] - 1
        i = idx[x]
        j = i+1 if i < N-1 else i-1
        y = A[j]
        A[i], A[j] = A[j], A[i]
        idx[x], idx[y] = j, i
    print(*[i+1 for i in A])
