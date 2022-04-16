# https://atcoder.jp/contests/abc227/tasks/abc227_d
# just binary search on answer and realize can greedy
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    N, K = intput()
    A = [*intput()]
    l, r = 1, 1<<60
    while l < r:
        p = (l+r+1) // 2
        s = sum( min(x,p) for x in A )
        if s >= p*K: l = p
        # if s//K >= p: l = p  # can divide to avoid overflow if c++
        else: r = p-1
    print(l)
