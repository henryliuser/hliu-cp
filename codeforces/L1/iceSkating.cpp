#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    int cnt = 0;
    unordered_map<int, int> psz;
    void add(int a) {
        if (psz.count(a)) return;
        psz[a] = -1;
        ++cnt;
    }
    bool unite(int a, int b) {
        add(a), add(b);
        a = find(a), b = find(b);
        if (a == b) return false;
        if (psz[a] > psz[b]) swap(a, b);
        psz[a] += psz[b];
        psz[b] = a;
        --cnt;
        return true;
    }
    int find(int a) {
        if (psz[a] < 0) return a;
        return psz[a] = find(psz[a]);
    }
};

int main() {
    DSU uf;
    int N; cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y;
        uf.unite(x, -y);
    }
    cout << uf.cnt-1 << '\n';
}
