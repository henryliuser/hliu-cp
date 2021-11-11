intput = lambda : map(int, input().split())

N,M = intput()
count = N
parent = [-1] * N
size = [1] * N
def unite(a, b):
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
for i in range(M):
    a,b = intput()
    unite(a,b)
    print(count)
