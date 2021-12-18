# https://codeforces.com/contest/1620/problem/E
# process queries in reverse.
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    A, queries = [], []
    f = [i for i in range(500001)]
    Q, = intput()
    for _ in range(Q):
        q = tuple(intput())
        queries.append(q)
    for q in reversed(queries):
        if q[0] == 1:
            x = q[1]
            A.append( f[x] )
        if q[0] == 2:
            x, y = q[1:]
            f[x] = f[y]
    print(*A[::-1])
