# https://atcoder.jp/contests/abc231/tasks/abc231_d
# don't be stupid next time.
# check cycles + degree > 2
import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

psz = []
def find(u):
    if psz[u] < 0: return u
    psz[u] = find(psz[u])
    return psz[u]

def unite(u, v):
    u, v = find(u), find(v)
    if u == v: return 0
    if psz[u] > psz[v]: u,v = v,u
    psz[u] += psz[v]
    psz[v] = u
    return 1

def solve():
    global psz
    N, M = intput()
    deg = [0] * (N+1)
    psz = [-1] * (N+1)
    A = [intput() for _ in range(M)]
    for a,b in A:
        deg[a] += 1
        deg[b] += 1
        if deg[a] > 2 or deg[b] > 2:
            return "No"
        if not unite(a, b):
            return "No"

    return "Yes"

if __name__ == '__main__':
    print( solve() )
