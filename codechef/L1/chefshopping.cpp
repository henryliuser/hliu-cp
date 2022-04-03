#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

struct DSU {
    int count;
    vector<int> psz;
    DSU(int n) : count(n), psz(n, -1) {}
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (psz[a] > psz[b]) swap(a, b);
        psz[a] += psz[b];
        psz[b] = a;
        --count;
        return true;
    }
    int find(int a) {
        if (psz[a] < 0) return a;
        return psz[a] = find(psz[a]);
    }
};

ll solve() {
    int N; cin >> N;
    vector<array<ll, 3>> edges;
    for (int x, i=0; i < N; ++i) {
        cin >> x;
        if (!i) continue;
        edges.push_back({x, i, i-1});
    }
    for (int x, i=0; i < N; ++i) {
        cin >> x;
        if (i==N-1) continue;
        edges.push_back({x, i, i+1});
    }
    DSU uf(N);
    ll ans = 0;
    sort(begin(edges), end(edges));
    for (auto &e : edges) {
        ans += e[0] * (uf.unite(e[1], e[2]));
        if (uf.count == 1) break;
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
