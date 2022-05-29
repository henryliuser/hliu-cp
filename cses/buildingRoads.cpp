// https://cses.fi/problemset/task/1666
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    DSU uf(N);
    for (int u,v, i=0; i < M; ++i) {
        cin >> u >> v;
        uf.unite(u-1, v-1);
    }
    cout << uf.count - 1 << '\n';
    vector<int> rts;
    for (int i = 0; i < N; ++i)
        if (uf.psz[i] < 0)
            rts.push_back(i+1);
    for (int i = 1; i < rts.size(); ++i)
        cout << rts[i-1] << " " << rts[i] << '\n';
}
