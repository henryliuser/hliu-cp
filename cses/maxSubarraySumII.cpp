#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, a, b;
    cin >> N >> a >> b;
    vector<ll> A(N);
    for (ll &x : A) cin >> x;

    ll ans = -1e18;
    multiset<ll> active;
    vector<ll> pre(N+1);
    for (int i = 1; i <= N; ++i) {
        pre[i] = A[i-1] + pre[i-1];
        if (i >= b+1)
            active.erase( active.find( pre[i-b-1] ) );
        if (i >= a) {
            active.insert(pre[i-a]);
            ans = max(ans, pre[i] - *begin(active));
        }
    }
    cout << ans << '\n';
}
