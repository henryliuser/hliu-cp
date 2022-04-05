// https://codeforces.com/contest/1657/problem/D
// unit i, monster j
// (hj / x*di) < (hi / dj)
// hj*dj < x*di*hi
// find the best x*di*hi for each c, in C log C (loop on c, x)
// let dp = prefix max of best
// upper_bound dp for each hj*dj.
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

int N, C, M;
map<ll, ll> units;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> C;
    for (ll c,d,h, i=0; i < N; ++i) {
        cin >> c >> d >> h;
        units[c] = max(units[c], d*h);
    }
    // prefix max lol
    for (auto it = next(begin(units)); it != end(units); ++it)
        it->second = max(it->second, prev(it)->second);

    vector<ll> dp(C+1);
    for (int c = 1; c <= C; ++c) {
        for (int x = 1; c*x <= C; ++x) {
            auto it = units.lower_bound(c);
            if (it == end(units)) --it;
            if (it->first > c) {
                if (it == begin(units)) break;
                --it;
            }
            dp[c*x] = max(dp[c*x], x*it->second);
        }
    }
    for (int c = 1; c <= C; ++c)
        dp[c] = max(dp[c], dp[c-1]);

    cin >> M;
    for (ll h,d, i=0; i < M; ++i) {
        cin >> d >> h;
        auto it = upper_bound(all(dp), d*h);
        ll ans = it - begin(dp);
        if (ans > C) ans = -1;
        cout << ans << ' ';
    }

}
