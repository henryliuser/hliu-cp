#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll ans = 0;
    int N, M; cin >> N >> M;
    vector<ll> C(N), T(M);
    for (ll &x : C) cin >> x;
    for (ll &x : T) cin >> x;

    for (int i = 0; i < N; ++i) {
        ll x = C[i];
        auto it = lower_bound(begin(T), end(T), x);
        if (it == end(T)) {
            ans = max(ans, x - *prev(it));
            continue;
        }
        ll diffR = *it - x;
        if (it == begin(T)) {
            ans = max(ans, diffR);
            continue;
        }
        ll diffL = x - *prev(it);
        ans = max(ans, min(diffL, diffR));
    }
    cout << ans << "\n";

}
