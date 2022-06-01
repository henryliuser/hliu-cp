// https://codeforces.com/problemset/problem/1677/C
// decompose into cycle graph, then greedy
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

#define int long long
#define  ll long long

ll solve() {
    int N; cin >> N;
    vector<int> A(N), B(N), P(N);
    for (int &x : A) cin >> x;
    for (int &x : B) cin >> x;
    for (int i = 0; i < N; ++i)
        P[ A[i]-1 ] = B[i]-1;

    set<int> s;
    for (int i = 1; i <= N; ++i) s.insert(i);
    vector<bool> vis(N);
    vector<vector<int>> cycs;
    for (int i = 1; i <= N; ++i) s.insert(i);
    for (int i = 0; i < N; ++i) {
        vector<int> v;
        while (!vis[i]) {
            vis[i] = true;
            v.push_back(i);
            i = P[i];
        }
        if (v.size() <= 1) continue;
        cycs.push_back(v);
    }
    ll ans = 0;
    for (auto &v : cycs) {
        int m = v.size();
        m -= m % 2;
        vector<int> x(m);
        for (int i = 0; i < m; ++i) {
            x[i] = ( i%2 ? *begin(s) : *s.rbegin() );
            s.erase(x[i]);
        }
        for (int i = 0; i < m; ++i) {
            int j = (i+1) % m;
            ans += abs(x[i] - x[j]);
        }
    }
    return ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
