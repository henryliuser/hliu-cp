import sys
from collections import defaultdict
intput = lambda : map(int, input().split())

def union(a, b):
    global count
    a, b = find(a), find(b)
    if a == b: return False
    if size[a] < size[b]: a,b = b,a
    parent[b] = a
    size[a] += size[b]
    count -= 1
    return True

def find(a):
    if parent[a] == -1: return a
    parent[a] = find(parent[a])
    return parent[a]

if __name__ == '__main__':
    sys.stdin  = open('fencedin.in',  'r')
    sys.stdout = open('fencedin.out', 'w')
    ans = 0
    A, B, n, m = intput()
    count  = (n+1) * (m+1)
    size   = defaultdict(lambda : 1)
    parent = defaultdict(lambda : -1)
    vert = [0] + sorted( int(input()) for _ in range(n) ) + [A]
    hori = [0] + sorted( int(input()) for _ in range(m) ) + [B]
    edges = []
    for i in range(n+1):
        w = vert[i + 1] - vert[i]
        for j in range(m):
            a, b = (j,i), (j+1,i)
            edges.append( (w,a,b) )
    for j in range(m+1):
        w = hori[j + 1] - hori[j]
        for i in range(n):
            a, b = (j,i), (j,i+1)
            edges.append( (w,a,b) )
    edges.sort()
    for e in edges:
        w, a, b = e
        if find(a) == find(b):
            continue
        union(a, b)
        ans += w
        if count == 1:
            break

    print(ans)
