import sys
from collections import deque, defaultdict
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

# strange top sort thing...
# maybe we want to minimize the amount of edges removed
# to create a DAG? then permute the remaining edges greedily somehow
# but also, it seems like at each node/flavor, we have to erase an edge
# without taking it. That represents a cow getting their first choice
# and we mark the current node as seen when we do that, so later nodes
# can't use us again. we mark adjacent nodes as seen if we TAKE edges to them,
# representing a cow getting their second choice.
# idk.
def solve():
    N, M = intput()
    A = [0] * (N+1)
    B = [0] * (N+1)
    indeg = [0] * (M+1)
    oudeg = [0] * (M+1)
    edges = defaultdict(set)
    adj = [[] for _ in range(M+1)]
    for i in range(1,N+1):
        a, b = intput()
        A[i], B[i] = a,b
        adj[a] += [b]
        edges[ (a,b) ] |= {i}
        indeg[b] += 1
        oudeg[a] += 1

    def hunger(L):
        cur = set()
        for x in L:
            if A[x] not in cur:
                cur.add(A[x])
            elif B[x] not in cur:
                cur.add(B[x])
        return N - len(cur)

    # it seems like there are a ton of edge cases
    # with this bfs thing... it's hard to decide
    # which edges to "delete" and which edges to "take"
    ans = []
    q = deque()
    done = [0] * (M+1)
    reserve = list(range(1, M+1))
    reserve.sort(key=lambda x: (indeg[x], -oudeg[x]))  # no idea how to prioritize stuff here
    rc = 0
    while q or rc < M:
        if not q:
            for j in range(rc, M):
                r = reserve[j]
                if not done[r]:
                    q.append(r)
                    rc = j+1
                    break
        if not q: break
        u = q.popleft()
        # vvv  yeah no idea about this one either lol
        pos = sorted(adj[u], key=lambda x: (-done[x], -oudeg[x], -indeg[x]))
        if not done[u] and pos:  # delete an edge
            done[u] = True
            v = pos[0]
            indeg[v] -= 1
            ans += [edges[(u,v)].pop()]
            pos = pos[1:]
        for v in pos:  # take edges
            if not done[v]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    done[v] = 1
                    ans += [edges[(u,v)].pop()]
                    q.append(v)
        done[u] = 1  # uhh idk

    rem = set(range(1, N + 1)) - set(ans)
    ans += list(rem)
    h = hunger(ans)
    return h, ans

if __name__ == '__main__':
    c, s = solve()
    print(c)
    for u in s:
        print(u)
