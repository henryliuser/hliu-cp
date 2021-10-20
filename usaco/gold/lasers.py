import sys
from queue import Queue
from bisect import bisect_left
from collections import defaultdict
intput = lambda : map(int, input().split())

# 0: right, 1: down, 2: left, 3: up
xs = defaultdict(list)
ys = defaultdict(list)

def bfs():
    seen = set()
    q = Queue()
    for d in range(4):
        q.put( (d, xl, yl, 0) )
        seen.add( (d,xl,yl) )
    while not q.empty():
        d, x, y, m = q.get(False)
        if d == 0: r, L = range(bisect_left(xs[y], x)+1, len(xs[y])), xs[y]
        if d == 1: r, L = range(bisect_left(ys[x], y)+1, len(ys[x])), ys[x]
        if d == 2: r, L = range(bisect_left(xs[y], x)), xs[y]
        if d == 3: r, L = range(bisect_left(ys[x], y)), ys[x]
        for i in r:
            if d%2 == 0: nx, ny = L[i], y
            if d%2 == 1: nx, ny = x, L[i]
            if (nx, ny) == (xb, yb):
                return m
            a = (1-d%2, nx, ny)
            b = (3-d%2, nx, ny)
            if a not in seen: q.put( (*a, m+1) )
            if b not in seen: q.put( (*b, m+1) )
            seen.add(a), seen.add(b)
    return -1


if __name__ == '__main__':
    sys.stdin  = open('lasers.in',  'r')
    sys.stdout = open('lasers.out', 'w')
    fences = []
    N, xl, yl, xb, yb = intput()
    fences.append( (xl, yl) )
    fences.append( (xb, yb) )
    for _ in range(N):
        x, y = intput()
        fences.append( (x,y) )
    for i in range(N+2):
        x, y = fences[i]
        xs[y].append(x)
        ys[x].append(y)
    for x in xs: xs[x].sort()
    for y in ys: ys[y].sort()

    print( bfs() )
