#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int count, maxSize;
    vector<int> parent, size;
    DSU(int n) : count(n), parent(n, -1), size(n, 1), maxSize(1) {}
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        maxSize = max(maxSize, size[a]);
        --count;
        return true;
    }
    int find(int a) {
        if (parent[a] == -1) return a;
        return parent[a] = find(parent[a]);
    }
};

int main() {
    int n, m; cin >> n >> m;
    DSU uf{n};
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        uf.unite(--x, --y);
        printf("%d %d\n", uf.count, uf.maxSize);
    }

}
