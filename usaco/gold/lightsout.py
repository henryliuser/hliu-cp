# misses cases 2 and 8. not sure why

import sys
Q = (1 << 21) - 9
B = 0
def rabin_karp(src, m, st):
    h, d, t = pow(2, B*m-B, Q), pow(2, B, Q), 0
    if st+m > len(src): return False  # should never happen, i think
    for i in range(st, st+m):
        t = (d*t + src[i]) % Q
    first = t
    for i in range(st+m, len(src)):
        t = (d*(t-src[i-m]*h) + src[i]) % Q
        if t == first: return True  # duplicate
    return False  # no dupe

if __name__ == '__main__':
    sys.stdin  = open('lightsout.in',  'r')
    sys.stdout = open('lightsout.out', 'w')
    N = int(input())
    B = N+1
    ihash, edges = {}, []
    points = [tuple(map(int, input().split())) for _ in range(N)]
    points.append(points[0])
    presum = [0]
    last = points[0]
    dir = -1  # 0: up, 1: right, 2: down, 3: left
    for i in range(1, N+1):
        curr = points[i]
        x0, y0 = last
        x1, y1 = curr
        length = abs(x1-x0) + abs(y1-y0)
        presum.append(presum[-1] + length)
        left = False
        if y1 > y0:
            dir, left = 0, (dir == 1 or dir == -1)
        if y0 > y1:
            dir, left = 2, (dir == 3 or dir == -1)
        if x1 > x0:
            dir, left = 1, (dir == 2 or dir == -1)
        if x0 > x1:
            dir, left = 3, (dir == 0 or dir == -1)

        key = (length, left)  # enumerate unique (length, dir) pairs
        if key in ihash:
            edges.append(ihash[key])
        else:
            ic = len(ihash)
            ihash[key] = ic
            edges.append(ic)
        last = curr

    ans = 0
    for i in range(1, N):  # iterate over starting edge
        e = edges[i]
        lit = min(presum[i], presum[-1] - presum[i])
        for length in range(1, N):  # iterate over lengths
            if rabin_karp(edges, length, i):  # if duplicate
                continue
            curr = i+length
            dist = presum[curr] - presum[i]
            dist += min(presum[curr], presum[-1]-presum[curr])
            ans = max(ans, dist-lit)
            break
    print(ans)
