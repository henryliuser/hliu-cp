// http://usaco.org/index.php?page=viewproblem2&cpid=1211
// add closest for each y and MST
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define tl(x) array<ll,x>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
const ll INF = 1e18;


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

ll dist(ll x1, ll y1, ll x2, ll y2) {
    ll dx = abs(x2-x1);
    ll dy = abs(y2-y1);
    return dx*dx + dy*dy;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    vector<tl(2)> cows(N);
    for (auto &c : cows)
        cin >> c[0] >> c[1];
    sort( all(cows) );

    vector<tl(3)> edges;
    map<int,pair<int,int>> last;
    for (int i = 0; i < N; ++i) {
        auto &c = cows[i];
        int x1 = c[0], y1 = c[1];
        for (auto [y2, p] : last) {
            auto [x2, j] = p;
            ll d = dist(x1,y1,x2,y2);
            edges.push_back( {d,i,j} );
        }
        last[y1] = {x1,i};
    }

    DSU uf(N);
    ll ans = 0;
    sort( all(edges) );
    for (auto &e : edges) {
        if (uf.unite( e[1], e[2] ))
            ans += e[0];
        if (uf.count == 1) break;
    }
    cout << ans << '\n';
}
