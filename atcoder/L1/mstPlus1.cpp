#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = array<ll, 4>;

#define all(x) (x).begin(), (x).end()

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
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<edge> E(M), qry(Q);
    for (edge &e : E) cin >> e[1] >> e[2] >> e[0];
    for (int i = 0; i < Q; ++i) {
        edge &e = qry[i];
        cin >> e[1] >> e[2] >> e[0];
        e[3] = i;
    }

    DSU uf(N+1);
    int i = 0, j = 0;
    vector<bool> ans(Q);
    sort(all(E)), sort(all(qry));
    for (int j = 0; j < Q; ++j) {
        while (i < M && E[i][0] < qry[j][0]) {
            uf.unite(E[i][1], E[i][2]);
            ++i;
        }
        if (i >= M) break;
        int a = uf.find(qry[j][1]);
        int b = uf.find(qry[j][2]);
        int k = qry[j][3];
        ans[k] = (a != b);
    }

    for (bool b : ans)
        cout << ( (b) ? "Yes" : "No" ) << '\n';
}
