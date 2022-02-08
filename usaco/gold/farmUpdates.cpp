// http://usaco.org/index.php?page=viewproblem2&cpid=1186
// dfsates can ONLY make farms irrelevant
// the moment a cow becomes irrelevant is the latest query it's relevant
// an active component is one with at least 1 active farm
// all farms in an active component are relevant
// once a component deactivates, the component will never change
// a node is irrelevant AFTER it is deactivated and cut from active comps
// go forwards then determine final state
// go backwards to undo "deletions"
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
#define pi(x) array<int, x>

vector<int> ans, vis;
vector<vector<int>> adj;

void dfs(int u, int q) {
    ans[u] = q;
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v, q);
}

struct DSU {
    vector<pi(2)> psz;
    DSU(int n) : psz(n, {-1,1}) {}
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (psz[a][0] > psz[b][0]) swap(a, b);
        psz[a][0] += psz[b][0];
        psz[a][1] += psz[b][1];
        psz[b][0] = a;
        return true;
    }
    int find(int a) {
        if (psz[a][0] < 0) return a;
        return psz[a][0] = find(psz[a][0]);
    }
    int relevant(int a) {
        return psz[find(a)][1];
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<pi(3)> qry(Q);
    multiset<pi(2)> cur;
    vector<pi(2)> edges;
    vector<bool> active(N+1, 1);

    char t; int s, d;
    for (int q = 0; q < Q; ++q) {
        cin >> t;
        if (t == 'D') {
            cin >> s;
            active[s] = 0;
        }
        if (t == 'A') {
            cin >> s >> d;
            edges.push_back( {s,d} );
            cur.insert( {s,d} );
        }
        if (t == 'R') {
            cin >> s;
            auto it = cur.find( edges[s-1] );
            cur.erase(it);
        }
        qry[q] = {t,s,d};
    }

    DSU uf(N+1);
    adj.resize(N+1);
    vis.resize(N+1);
    for (int i = 1; i <= N; ++i)
        uf.psz[i][1] = active[i];
    for (auto &e : cur)
        uf.unite(e[0], e[1]),
        adj[e[0]].push_back(e[1]),
        adj[e[1]].push_back(e[0]);

    ans.assign(N+1, -1);
    for (int i = 1; i <= N; ++i)
        if (active[i] || uf.relevant(i))
            ans[i] = Q;

    for (int q = Q-1; q >= 0; --q) {
        t = qry[q][0], s = qry[q][1], d = qry[q][2];
        if (t == 'D') {
            int j = uf.find(s);
            if (!uf.relevant(j)) dfs(s, q);
            uf.psz[j][1] += 1;
        }
        if (t == 'A') continue;
        if (t == 'R') {
            int a = edges[s-1][0];
            int b = edges[s-1][1];
            int u = uf.relevant(a);
            int v = uf.relevant(b);
            if (!u && v) dfs(a, q);
            if (!v && u) dfs(b, q);
            uf.unite(a, b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    for (int i = 1; i <= N; ++i)
        cout << ans[i] << '\n';
}
