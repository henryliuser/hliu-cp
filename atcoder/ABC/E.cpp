#include <bits/stdc++.h>
using namespace std;
using edge = array<int, 2>;
using ll = long long;

struct DSU {
    int count = 0;
    unordered_map<int, int> psz;
    void add(int a) {
        if (psz.count(a)) return;
        psz[a] = -1;
        ++count;
    }
    bool unite(int a, int b) {
        add(a); add(b);
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
    int N, M; cin >> N >> M;
    vector<edge> E(M);
    for (edge &e : E) {
        cin >> e[0] >> e[1];
        --e[0], --e[1];
    }
    sort(begin(E), end(E), [](auto &a, auto &b)
    { if (a[0] == b[0]) return a[1] > b[1];
    else return a[0] > b[0]; });

    DSU uf;
    int ec = 0;
    vector<int> ans(N);
    for (int i = N-1; i >= 0; --i) {
        ans[i] = uf.count;
        uf.add(i);
        while (ec < M && E[ec][0] >= i && E[ec][1] >= i) {
            uf.unite(E[ec][0], E[ec][1]);
            ++ec;
        }
    }
    for (int x : ans)
        cout << x << "\n";
}
