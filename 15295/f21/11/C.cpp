#include <bits/stdc++.h>
using namespace std;
using tup = tuple<int, int, int, int>;

int N, M, K;
int u, v, c, q;

struct DSU {
    int count;
    vector<int> psz;
    void init(int n) {
        count = n;
        psz.assign(n, -1);
    }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (psz[a] > psz[b]) swap(a, b);
        psz[b] = a;
        --count;
        return true;
    }
    int find(int a) {
        if (psz[a] < 0) return a;
        return psz[a] = find(psz[a]);
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    vector<DSU> uf(K);
    vector<int> ans(M);
    vector<tup> edges;
    for (int i = 0; i < K; ++i)
        uf[i].init(N+1);
    for (int i = 0; i < M; ++i) {
        cin >> u >> v >> c;
        edges.emplace_back(-c,u,v,i);
    }

    sort(begin(edges), end(edges));
    for (int i = 0; i < M; ++i) {
        tie(c,u,v,q) = edges[i];
        int lo = 0, hi = K;
        while (lo < hi) {
            int mid = lo + (hi-lo) / 2;
            if (uf[mid].same(u, v))
                lo = mid+1;
            else
                hi = mid;
        }
        if (lo == K)
            ans[q] = 0;
        else {
            uf[lo].unite(u, v);
            ans[q] = lo+1;
        }
    }
    for (int i = 0; i < M; ++i)
        cout << ans[i] << "\n";
}
