#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = tuple<int, int, int>;

struct DSU {
    int count;
    vector<int> size, parent;
    DSU(int n) : count(n), parent(n, -1), size(n, 1) {}
    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
        --count;
    }
    int find(int a) {
        if (parent[a] == -1) return a;
        return parent[a] = find(parent[a]);
    }
};

int main() {
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    ll ans = 0;
    int A, B, n, m;
    cin >> A >> B >> n >> m;
    DSU uf((n+1)*(m+1));
    vector<int> vert(n+2), hori(m+2);
    vert[0] = 0, vert[n+1] = A;
    hori[0] = 0, hori[m+1] = B;
    for (int i = 0; i < n; ++i) cin >> vert[i+1];
    for (int i = 0; i < m; ++i) cin >> hori[i+1];
    sort(begin(vert), end(vert));
    sort(begin(hori), end(hori));
    vector<edge> edges;
    int dx = n+1;
    for (int i = 0; i < n+1; ++i) {
        int w = vert[i+1] - vert[i];
        for (int j = 0; j < m; ++j) {
            int a = j * dx + i;
            int b = (j+1) * dx + i;
            edges.push_back( {w,a,b} );
        }
    }
    for (int j = 0; j < m+1; ++j) {
        int w = hori[j+1] - hori[j];
        for (int i = 0; i < n; ++i) {
            int a = j * dx + i;
            int b = a + 1;
            edges.push_back( {w,a,b} );
        }
    }
    sort(begin(edges), end(edges));
    for (auto &e : edges) {
        auto [w,a,b] = e;
        if (uf.find(a) == uf.find(b))
            continue;
        uf.unite(a, b);
        ans += w;
        if (uf.count == 1)
            break;
    }
    cout << ans << endl;

}
