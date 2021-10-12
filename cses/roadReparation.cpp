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
    ll ans = 0;
    int n, m; cin >> n >> m;
    vector<edge> roads(m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        roads[i] = {c, --a, --b};
    }
    DSU uf(n);
    sort(begin(roads), end(roads));
    for (int i = 0; i < m; ++i) {
        auto [c,a,b] = roads[i];
        if (!uf.unite(a,b)) continue;
        ans += c;
        if (uf.count == 1) break;
    }
    if (uf.count != 1) printf("IMPOSSIBLE\n");
    else cout << ans << endl;

}
