// https://codeforces.com/contest/1611/problem/D
#include <bits/stdc++.h>
using namespace std;

vector<int> solve() {
    int N; cin >> N;
    vector<int> dist(N, -1);
    vector<int> par(N), perm(N);
    for (int &x : par) { cin >> x; --x; }
    for (int &x : perm) { cin >> x; --x; }
    int root = -1;
    for (int i = 0; i < N; ++i)
        if (par[i] == i) root = i;

    int mxd = 0;  // current max distance
    dist[root] = 0;
    vector<int> ans(N);
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
        for (int x : s) cout << x << " ";
        cout << "\n";
    }

}
