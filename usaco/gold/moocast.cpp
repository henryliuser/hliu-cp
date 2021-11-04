// N^2 log N^2 kruskal's mst
// can also binary search dfs in N^2 log 1e10 with high constant
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
#define f first
#define s second

int w, a, b;
struct DSU {
    int count;
    vector<int> parent, size;
    DSU(int n) : count(n), parent(n, -1), size(n, 1) {}
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

int dist(pii &a, pii &b) {
    int dx = a.f - b.f;
    int dy = a.s - b.s;
    return dx * dx + dy * dy;
}

int main() {
    int ans = 0;
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int N; cin >> N;
    vector<pii> cows(N);
    for (int i = 0; i < N; ++i)
        cin >> cows[i].f >> cows[i].s;

    DSU uf(N);
    vector<tup> edges;
    for (int i = 0; i < N; ++i)
        for (int j = i+1; j < N; ++j)
            edges.emplace_back(dist(cows[i], cows[j]), i, j);
    sort(begin(edges), end(edges));
    for (tup &e : edges) {
        tie(w, a, b) = e;
        if (uf.unite(a,b)) ans = w;
        if (uf.count == 1) break;
    }
    cout << ans << endl;
}
