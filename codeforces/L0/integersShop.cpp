#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = array<ll, 2>;

template <typename MP, typename KEY>
void update(MP &mp, KEY k, ll v) {
    if (!mp.count(k)) mp[k] = v;
    else mp[k] = min(mp[k], v);
}

void solve() {
    int N; cin >> N;
    vector<pl> A(N);
    vector<ll> cost(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i][0] >> A[i][1] >> cost[i];

    map<pl, ll> mp;
    map<ll, ll> best;
    ll lo = 1e18, hi = -1;
    for (int i = 0; i < N; ++i) {
        pl &p = A[i];
        lo = min(lo, p[0]);
        hi = max(hi, p[1]);
        update(mp, p, cost[i]);
        update(best, p[0], cost[i]);
        update(best, p[1], cost[i]);
        ll ans = best[lo] + best[hi];
        pl qry = {lo, hi};
        if (mp.count(qry))
            ans = min(ans, mp[qry]);
        cout << ans << '\n';
    }

}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}
