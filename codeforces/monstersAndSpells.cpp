// https://codeforces.com/contest/1626/problem/C
// merge intervals
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using iv = pair<ll, ll>;
const ll INF = 1e18;

#define all(x) (x).begin(), (x).end()

ll solve() {
    int N; cin >> N;
    vector<iv> ivals;
    vector<ll> H(N), K(N);
    for (ll &x : K) cin >> x;
    for (ll &x : H) cin >> x;

    for (int i = 0; i < N; ++i) {
        ll k = K[i];
        ll x = k - H[i] + 1;
        ivals.push_back( {x,k} );
    }
    ll ans = 0;
    sort( all(ivals) );
    ivals.push_back( {INF, 0} );
    ll curL = 1, curR = 0;
    for (int i = 0; i <= N; ++i) {
        auto [x,k] = ivals[i];
        if (x > curR) {
            ll y = curR - curL + 1;
            if (y % 2) ans += (y+1)/2 * y;
            else ans += y/2 * (y+1);
            curL = x;
        }
        curR = max(curR, k);
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
