// https://codeforces.com/problemset/problem/1624/G
// great question. Greedily eliminate bits from highest to lowest.
// eliminate bits by checking if graph is still connected after removing all
// edges with the current elimination mask `cur`.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = array<int, 3>;

struct DSU {
    int cnt;
    vector<int> pr;
    DSU(int n) : cnt(n), pr(n, -1) {}
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (pr[u] > pr[v]) swap(u, v);
        if (pr[u] == pr[v]) --pr[u];
        pr[v] = u;
        --cnt;
        return true;
    }
    int find(int u) {
        if (pr[u] < 0) return u;
        return pr[u] = find(pr[u]);
    }
};

ll solve() {
    int ans = 0;
    int N, M; cin >> N >> M;
    vector<edge> E(M);
    for (edge &e : E)
        cin >> e[1] >> e[2] >> e[0];

    int cur = 0;
    for (int b = 31; b >= 0; --b) {
        int bit = 1 << b;
        vector<int> idxs;
        for (int i = 0; i < M; ++i)
            if ((E[i][0] & (cur|bit)) == 0)
                idxs.push_back(i);

        DSU uf(N);
        for (int i : idxs)
            uf.unite(E[i][1]-1, E[i][2]-1);
        if (uf.cnt == 1) {
            cur |= bit;
            ans |= bit;
        }
    }
    return ~ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
