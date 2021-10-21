# tle cuz python bad
import sys
from collections import defaultdict
intput = lambda : map(int, input().split())

def dfs(u, s):
    s.remove(u)
    for v in graph[u]:
        if v in s:
            dfs(v, s)
    return len(s) == 0

if __name__ == '__main__':
    sys.stdin  = open('closing.in',  'r')
    sys.stdout = open('closing.out', 'w')
    N, M = intput()
    graph = defaultdict(list)
    for _ in range(M):
        a, b = intput()
        graph[a].append(b)
        graph[b].append(a)
    open = set(range(1,N+1))
    for i in range(N):
        for e in open: break  # lol
        print("YES" if dfs(e, set(open)) else "NO")
        open.remove(int(input()))
