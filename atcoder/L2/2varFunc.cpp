// https://atcoder.jp/contests/abc246/tasks/abc246_d
// loop on a, bounded by ~1e6.
// binary search on b.
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = unsigned long long;

ll ub = 1e6+5;

ll f(ll a, ll b) {
    return a*a*a + a*a*b + a*b*b + b*b*b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll N; cin >> N;

    ll ans = 1e18 + 5;
    for (ll a = 0; a <= ub; ++a) {
        ll lo = 0, hi = ub;
        while (lo < hi) {
            ll b = lo + (hi-lo)/2;
            ll y = f(a,b);
            if ( y >= N ) {
                hi = b;
                ans = min(ans, y);
                if (ans == N) break;
            }
            else lo = b+1;
        }
    }
    cout << ans << '\n';
}
