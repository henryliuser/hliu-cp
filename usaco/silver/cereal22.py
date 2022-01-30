import sys, time, random
from collections import deque, defaultdict
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())
sys.setrecursionlimit(1 << 20)

# this might unironically be the singular worst
# program I have ever authored in my career.
def solve():
    global passed, log, st
    N, M = intput()
    A = [0] * (N+1)
    B = [0] * (N+1)
    indeg = [0] * (M+1)
    oudeg = [0] * (M+1)
    edges = defaultdict(set)
    prefs = [[set(), set()] for _ in range(M+1)]
    adj = [[] for _ in range(M+1)]
    adj2 = [[] for _ in range(M+1)]
    for i in range(1,N+1):
        a, b = intput()
        A[i], B[i] = a,b
        adj[a] += [b]
        adj2[b] += [a]
        prefs[a][0] |= {i}
        prefs[b][1] |= {i}
        edges[ (a,b) ] |= {i}
        indeg[b] += 1
        oudeg[a] += 1
    st = time.time()

    def getComps():
        vis = [0] * (M+1)
        res = defaultdict(set)
        def dfs(u, c):
            vis[u] = 1
            res[c].add(u)
            for ad in (adj, adj2):  # extraordinarily dumb
                for v in ad[u]:
                    if not vis[v]:
                        dfs(v, c)
        for i in range(1, M+1):
            if not vis[i]:
                dfs(i, i)

        i = 0
        edgecomps = defaultdict(set)
        for comp in res.values():
            sq = set()
            for c in comp:
                for j in prefs[c][0]:
                    sq.add(j)
                for j in prefs[c][1]:
                    sq.add(j)
            if sq:
                edgecomps[i] = sq
                i += 1
        return edgecomps

    comps = getComps()
    def hunger(L):
        cur = set()
        for x in L:
            if A[x] not in cur:
                cur.add(A[x])
            elif B[x] not in cur:
                cur.add(B[x])
        return N - len(cur), cur

    ans = []
    done = [0] * (M+1)
    q = deque()
    for i in range(1, M+1):
        if indeg[i] == 0:
            q.append(i)
    reserve = list(range(1, M + 1))
    reserve.sort(key=lambda x: (indeg[x], -oudeg[x]))  # no idea
    rc = 0
    while q or rc < M:
        if not q:
            for j in range(rc, M):
                r = reserve[j]
                if not done[r]:
                    q.append(r)
                    rc = j + 1
                    break
        if not q: break
        u = q.popleft()
        pos = sorted(adj[u], key=lambda x: (-done[x], -oudeg[x], indeg[x]))
        if not done[u] and pos:  # delete an edge
            done[u] = True
            v = pos[0]
            indeg[v] -= 1
            if indeg[v] <= 0 and not done[v]:
                q.append(v)
            try: ans += [edges[(u,v)].pop()]
            except: pass
            pos = sorted(pos[1:], key=lambda x: (-oudeg[x], -indeg[x]))
        for v in pos:  # take edges
            if not done[v]:
                indeg[v] -= 1
                try: ans += [edges[(u, v)].pop()]
                except: pass
                if indeg[v] <= 0:
                    done[v] = True
                    q.append(v)
        done[u] = True

    def bubble(p=None):
        ans = []
        fp = set()
        if not p: p = range(1, N+1)
        for i in p:
            if A[i] not in fp:
                fp.add(A[i])
                ans += [i]
            elif B[i] not in fp:
                fp.add(B[i])
                ans += [i]
            else:  # greedy swap
                for j in range(len(ans)):  # bubble upwards or something
                    # if swapping i,j would allow i to not be hungry, do it
                    # no idea why this would work
                    t = ans[:]
                    tj = t[j]
                    t[j] = i
                    Q = hunger(t)[1]
                    if len(Q) < len(fp): continue
                    if A[tj] in Q and B[tj] in Q: continue
                    if A[tj] not in Q:
                        Q.add(A[tj])
                    elif B[tj] not in Q:
                        Q.add(B[tj])
                    t += [tj]
                    fp = Q
                    ans = t
                    break
                else:
                    ans += [i]
        return N-len(fp), ans

    # def pfxmethod():
    #     done = [0] * (M+1)
    #     reserve = sorted(range(1, M+1), key=lambda x:(-(icp[x]==0), -ocp[x]))
    #     for fs in range(1,N):
    #         second = {}
    #         for i in range(fs):
    #             r = reserve[i]
    #             for j in prefs[r][0]:
    #                 b = B[j]
    #                 for c in prefs[b][1]:
    #
    #             ans += [r]

    def perCompCheese(its=20):
        tans = []
        for c in comps.values():
            c = list(c)
            bh = hunger(c)
            for j in range(its):
                p = c[:]
                random.shuffle(p)
                h = hunger(p)
                if h < bh:
                    bh = h
                    c = p
            tans += c
        return hunger(tans)[0], tans

    rem = set(range(1, N + 1)) - set(ans)
    ans += list(rem)
    h = hunger(ans)[0]

    if N <= 150:
        h2, ans2 = bubble()
        h3, ans3 = bubble(ans)
        if h2 < h:
            h = h2
            ans = ans2
        if h3 < h:
            h = h3
            ans = ans3
        for j in range(25):
            p = list(range(1,N+1))
            random.shuffle(p)
            h2, ans2 = bubble(p)
            h3 = hunger(p)[0]
            if h2 < h:
                h = h2
                ans = ans2
            if h3 < h:
                h = h3
                ans = p
    # else:
    #     for j in range(1):
    #         p = list(range(1, N + 1))
    #         random.shuffle(p)
    #         h2 = hunger(p)[0]
    #         if h2 < h:
    #             h = h2
    #             ans = p

    its = 20 if N <= 150 else 1
    qwe, qwe2 = perCompCheese(its)
    if qwe < h:
        h = qwe
        ans = qwe2

    # ANS, EXS = check(A, B, N, M)
    # print('real ans:', ANS)
    # print('example: ', *EXS[0])
    # for e in EXS:
    #     print(*e)
    # if h == ANS: passed += 1
    # elif LOG:
    #     log.write(f"{N} {M}\n")
    #     for i in range(1, N+1):
    #         log.write(f"{A[i]} {B[i]}\n")
    #     log.write("\n")

    # outf = open('/Users/henryliu/Desktop/DEBUG/py/77.out', 'w')
    # for e in EXS:
    #     outf.write(' '.join(map(str,e)) + '\n')
    # outf.close()
    return h, ans

if __name__ == '__main__':
    st = 0
    c, s = solve()
    # print('time:', time.time() - st)
    print(c)
    for u in s:
        print(u)
