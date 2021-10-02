from collections import defaultdict
intput = lambda : map(int, input().split())

n, m = intput()
graph = [set() for _ in range(n+1)]
for _ in range(m):
    a, b = intput()
    graph[a].add(b)
    graph[b].add(a)

def solve():
    i = 0
    curr = set()
    vc = [set(), set()]
    def dfs(u):
        nonlocal i, curr
        if u in vc[i]: return
        vc[i].add(u)
        for v in graph[u]:
            curr.add(v)
        if len(curr) == n:
            if i == 1: raise ValueError()
            i, curr = 1, set()
        for v in graph[u]:
            dfs(v)

    try: dfs(1)
    except: return vc
    return -1

if __name__ == '__main__':
    s = solve()
    if s == -1:
        print(s)
    else:
        for i in range(2):
            print(len(s[i]))
            print(' '.join(map(str, s[i])))
