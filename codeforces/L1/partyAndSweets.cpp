// https://codeforces.com/problemset/problem/1158/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    int N, M; cin >> N >> M;
    vector<ll> B(N), G(M);
    for (ll &x : B) cin >> x;
    for (ll &x : G) cin >> x;
    sort(begin(B), end(B));
    sort(begin(G), end(G));
    if (G[0] < B[N-1]) return -1;
    ll x = B[N-1];
    ll ans = 0;
    for (int i = 1; i < M; ++i)
        ans += G[i];
    if (G[0] == x) {
        ans += x;
        ans += B[N-2] * M;
    }
    else ans += G[0] + x + B[N-2] * (M-1);
    for (int i = 0; i < N-2; ++i)
        ans += B[i] * M;
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << solve() << "\n";

}
