# https://atcoder.jp/contests/abc249/tasks/abc249_d
# main constraint is A[i] <= 2e5
# this lets you iterate over all pairs in N log N
import sys
from collections import defaultdict
input = lambda: sys.stdin.readline().strip()
intput = lambda: map(int, input().split())

def solve():
    N, = intput()
    A = [*intput()]
    freq = defaultdict(int)
    for x in A:
        freq[x] += 1

    B = [(x,freq[x]) for x in sorted(freq)]
    N = len(B)

    ans = 0
    mx = B[-1][0]
    for i in range(N):
        a, c = B[i]
        if a == 1: continue
        for j in range(i+1):
            b, d = B[j]
            if b == 1: continue
            prod = a*b
            if prod > mx: break  # makes it n log n
            e = freq[prod]
            q = c*d*e
            if i != j: q *= 2
            ans += q

    if 1 in freq:
        os = freq.pop(1)
        ans += os**3
        res = 0
        for k,v in freq.items():
            res += v*v
        ans += os * res * 2

    return ans

if __name__ == '__main__':
    print( solve() )
