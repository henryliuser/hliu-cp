#include <bits/stdc++.h>
using namespace std;
using tup = tuple<int, int, int>;

struct DSU {
    int count;
    vector<int> parent, size;
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
        --count;
        return true;
    }
    int find(int a) {
        if (parent[a] == -1) return a;
        return parent[a] = find(parent[a]);
    }
    DSU(int n) : count(n), parent(n, -1), size(n, 1) {}
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int x, a, b, c, d;
    vector<tup> edges;
    for (int i = 0; i < N; ++i) {
        cin >> x >> a >> b >> c >> d;
        edges.emplace_back(0, a-1, b-1);
        edges.emplace_back(0, c-1, d-1);
        edges.emplace_back(x, a-1, c-1);
    }
    DSU uf(2*N);
    int ans = 0;
    sort(begin(edges), end(edges));
    for (auto e : edges) {
        tie(c,a,b) = e;
        if (uf.unite(a,b)) ans += c;
        if (uf.count == 1) break;
    }
    cout << ans << endl;

}
