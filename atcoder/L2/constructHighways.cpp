// https://atcoder.jp/contests/abc239/tasks/abc239_f
// 12x WA fml lol
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using pi = array<int, 2>;
void fail() { cout << "-1\n"; exit(0); }

int N, M;
vector<int> D;
vector<vector<pi>> avail;

struct DSU {
    vector<int> psz, sum;  // you can pass with psz as the sum directly.
    DSU(int n) : psz(n,-1), sum(n) {
        for (int u = 1; u < n; ++u)
            sum[u] = D[u];
    }
    inline bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (psz[a] > psz[b]) swap(a, b);
        psz[a] += psz[b];
        sum[a] += sum[b] - 2;  // both 'gained' an edge
        psz[b] = a;
        return true;
    }
    int find(int a) {
        if (psz[a] < 0) return a;
        return psz[a] = find(psz[a]);
    }
};

inline int upd(int u) {
    if (avail[u].empty()) fail();
    auto &[q,v] = avail[u].back();
    if (--q <= 0) avail[u].pop_back();
    --D[v];
    return v;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    D.resize(N+1);
    for (int u = 1; u <= N; ++u)
        cin >> D[u];

    DSU uf(N+1);
    for (int u,v, i=0; i < M; ++i) {
        cin >> u >> v;
        --D[u], --D[v];
        uf.unite(u, v);  // don't subtract
    }
    avail.resize(N+1);
    for (int u = 1; u <= N; ++u) {
        if (!D[u]) continue;
        if (D[u] < 0) fail();
        int t = uf.find(u);
        avail[t].push_back( {D[u],u} );
    }

    multiset<pi> comps;
    for (int u = 1; u <= N; ++u) {
        if (uf.psz[u] < 0)
            comps.insert( {uf.sum[u], u} );
    }

    vector<pi> ans;
    while (comps.size() > 1) {
        auto itl = begin(comps);      // should be 1
        auto itr = prev(end(comps));  // should be > 1
        auto u = *itl, v = *itr;

        if (u[0] <= 0 || v[0] <= 0) fail();

        comps.erase(itl), comps.erase(itr);
        ans.push_back( {upd(u[1]), upd(v[1])} );
        comps.insert( {v[0]-1, v[1]} );
    }
    for (int u = 1; u <= N; ++u)
        if (D[u] != 0) fail();

    for (auto &p : ans)
        cout << p[0] << " " << p[1] << '\n';
}
