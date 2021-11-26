#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> solve() {
    int N; cin >> N;
    vector<ll> dist(N, -1);
    vector<int> par(N), perm(N);
    for (int &x : par) { cin >> x; --x; }
    for (int &x : perm) { cin >> x; --x; }
    int root = -1;
    for (int i = 0; i < N; ++i)
        if (par[i] == i) root = i;

    ll mxd = 0;  // current max distance
    dist[root] = 0;
    vector<ll> ans(N);
    if (perm[0] != root) return {-1};
    for (int i = 1; i < N; ++i) {
        int u = perm[i];
        int p = par[u];
        if (dist[p] == -1) return {-1};
        ans[u] = mxd - dist[p] + 1;
        dist[u] = dist[p] + ans[u];
        mxd = max(mxd, dist[u]);
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {
        auto s = solve();
        for (ll x : s) cout << x << " ";
        cout << "\n";
    }

}
