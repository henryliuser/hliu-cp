import sys
from collections import defaultdict
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    C  = ' ' + input()
    adj = [[] for _ in range(N+1)]
    for _ in range(N-1):
        a, b = intput()
        adj[a] += [b]
        adj[b] += [a]

    root = bcnt = 0
    for i in range(1,N+1):
        if C[i] == 'B':
            root = i
            bcnt += 1
    if bcnt <= 1: return "YES"

    def dfs(u, p, cur):
        flag = False
        if C[u] == 'B' and p != 0:
            if cur['R'] == 0 or cur['G'] == 0:
                raise OSError()
            else:
                flag = True
        cur[C[u]] += 1
        for v in adj[u]:
            if v == p: continue
            if flag: dfs(v, u, defaultdict(int))
            else: dfs(v, u, cur)
        cur[C[u]] -= 1

    try:
        dfs(root, 0, defaultdict(int))
        return "YES"
    except:
        return "NO"

if __name__ == '__main__':
    T, = intput()
    for _ in range(T):
        print( solve() )
