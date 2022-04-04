# https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a45ef7
# nice problem. first note it's a tree.
# propagate the minimum path in subtree upwards, and just add the rest to ans
# build the potential paths from the bottom up
# interpret each node as a "junction", which needs to decide which of
# the incoming paths from underneath get to pass first (pick the minimum)
"""
1
11
20 50 30 40 17 16 1 2 1 2 3
0 1 1 1 3 3 4 4 6 6 6
"""
import sys
sys.setrecursionlimit(1<<20)  # RE without this, sad!
input  = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

def solve():
    N, = intput()
    adj = [[] for _ in range(N+1)]
    F = [0]  + [*intput()]
    P = [-1] + [*intput()]
    for i in range(1, N+1):
        adj[ P[i] ] += [i]

    ans = 0
    def dfs(u):
        nonlocal ans
        if not adj[u]:   # if leaf,
            return F[u]  # pass myself up

        lv = []
        for v in adj[u]:
            lv += [ dfs(v) ]
        lv.sort()

        for i in range(1, len(lv)):
            ans += lv[i]
        return max(F[u], lv[0])

    return dfs(0) + ans  # plus the final returned node

if __name__ == '__main__':
    T, = intput()
    for t in range(1,T+1):
        print(f"Case #{t}: ", end='')
        print( solve() )
