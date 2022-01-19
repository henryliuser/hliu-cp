# https://atcoder.jp/contests/abc235/tasks/abc235_d
# not hard im just illiterate 
import sys
from collections import deque
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

# def shift(s, t):
#     if len(s) != len(t): return -1
#     return (t+t).find(s)

def bfs():
    depth = 0
    q = deque(['1'])
    while q:
        sz = len(q)
        for _ in range(sz):
            z = q.popleft()
            x = int(z)
            if x in seen: continue
            if x == N: return depth
            # cyc = shift(z, T)
            # if cyc != -1: return depth + cyc
            seen.add(x)
            if len(z) <= len(T):
                q.append( str(a*x) )
            if x < 10 or x % 10 == 0: continue
            z = z[-1] + z[:-1]
            if int(z) in seen: continue
            q.append(z)
        depth += 1
    return -1

if __name__ == '__main__':
    seen = set()
    a, N = intput()
    T = str(N)
    print( bfs() )
