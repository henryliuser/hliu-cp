#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {    // cool memory optimization
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
    int N; cin >> N;
    vector<int> P(N);
    for (int &x : P) cin >> x;

    DSU uf(N);
    int M; cin >> M;
    while (M--) {
        int a, b; cin >> a >> b;
        uf.unite(a-1, b-1);
    }
}
