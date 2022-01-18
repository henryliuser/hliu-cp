// https://codeforces.com/contest/1627/problem/B
// just sort maxDists instead of sumDists
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

void solve() {
    vector<ll> dists;
    int N, M; cin >> N >> M;
    vector<vector<ll>> sum(N, vector<ll>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            ll L = j, U = i;
            ll R = M-j-1, D = N-i-1;
            ll mx = max(L, R) + max(U, D);
            dists.push_back(mx);
        }
    }
    sort(all(dists));
    for (int k = 0; k < N*M; ++k)
        cout << dists[k][0] << " ";
    cout << '\n';
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}
