#include <bits/stdc++.h>
using namespace std;
static constexpr int MXN = 1e6+1;
int parent[MXN], usize[MXN];
struct DSU {
    int count;
    DSU(int N) : count(N) {}
    bool unite(int a, int b) { // return on success
        a = find(a), b = find(b);
        if (a == b) return false; // cycle (undirected)
        if (usize[a] < usize[b]) swap(a, b);
        parent[b] = a;
        usize[a] += usize[b]; // size[b] not used after
        --count;
        return true;
    }
    int find(int v) {
        if (parent[v] == -1) return v;
        return parent[v] = find(parent[v]);
    }   // path compression
};

int main() {
    memset(parent, -1, sizeof parent);
    int N, M;
    scanf("%d %d", &N, &M);
    DSU uf(N);
    for (int i = 0; i < N; ++i) usize[i] = 1;
    while (M--) {
        int a, b; scanf("%d %d", &a, &b);
        uf.unite(a,b);
        printf("%d\n", uf.count);
    }

}
