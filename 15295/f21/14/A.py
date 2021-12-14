import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())


def unite(u, v, pr):
    u, v = find(u), find(v)
    if pr[u] > pr[v]: u,v = v,u
    if pr[u] == pr[v]: pr[u] -= 1
    pr[v] = u

def find(u, pr):
    if pr[u] < 0: return u
    pr[u] = find(pr[u])
    return pr[u]

def conn(u, v, pr):
    return find(u, pr) == find(v, pr)

def query():
    pass

if __name__ == '__main__':
    N, M, K = intput()
    N += 1
    F = [-1] * N
    T = [-1] * N
    adjF = [[] for _ in range(N)]
    adjT = [[] for _ in range(N)]
    for _ in range(M):
        a, b = intput()
        unite(a, b, F)
        adjF[a].append(b)
        adjF[b].append(a)
    for _ in range(K):
        a, b = intput()
        unite(a, b, T)
        adjT[a].append(b)
        adjT[b].append(a)

    # preprocess
    cnt = [0] * N
    for x in range(1,N):
        for y in adj[x]:
            if conn(x, y, T):
                cnt[x] += 1

    Q, = intput()
    for _ in range(Q):
        q = input().split()
        if q[0] == '?':

        if q[0] == 'F':
            a, b = q[1], q[2]
            unite(a, b, F)
            if conn(a, b, T):
                cnt[a] += 1
                cnt[b] += 1
        if q[1] == 'T':
            a, b = q[1], q[2]
            unite(a, b, T)
            if conn(a, b, F):
                cnt[a] += 1
                cnt[b] += 1
