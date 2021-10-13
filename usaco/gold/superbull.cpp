#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = tuple<int, int, int>;

struct DSU {
    int count;
    vector<int> size, parent;
    DSU(int n) : count(n), size(n, 1), parent(n, -1) {}
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        --count;
        return true;
    }
    int find(int a) {
        if (parent[a] == -1) return a;
        return parent[a] = find(parent[a]);
    }
};

int main() {
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
    ll ans = 0;
    int N; cin >> N;
    DSU uf(N);
    vector<int> id(N);
    vector<edge> edges;
    for (int i = 0; i < N; ++i) cin >> id[i];
    for (int i = 0; i < N; ++i)
        for (int j = i+1; j < N; ++j)
            edges.push_back( {-(id[i] ^ id[j]), i, j} );

    sort(begin(edges), end(edges));
    for (auto &e : edges) {
        auto [w,a,b] = e;
        if (uf.unite(a,b)) ans -= w;
        if (uf.count == 1) break;
    }
    cout << ans << endl;

}
