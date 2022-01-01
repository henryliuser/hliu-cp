import sys
from math import gcd
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    ans = set()
    N, = intput()
    A  = [tuple(intput()) for _ in range(N)]
    for i in range(N):
        a, b = A[i]
        for j in range(N):
            if i == j: continue
            c, d = A[j]
            dx, dy = c-a, d-b
            g = gcd(dx, dy)
            ans.add( (dx//g, dy//g) )

    print( len(ans) )
