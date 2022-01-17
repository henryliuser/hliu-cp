import sys
from collections import defaultdict
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    N, Q = intput()
    A = list(intput())
    mp = defaultdict(list)
    for i,x in enumerate(A):
        mp[x] += [i]
    for _ in range(Q):
        x,k = intput()
        if len(mp[x]) < k: print(-1)
        else: print(mp[x][k-1]+1)
