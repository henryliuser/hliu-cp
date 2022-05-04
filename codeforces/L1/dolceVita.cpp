// https://codeforces.com/problemset/problem/1671/C
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)

ll solve() {
    ll N, X;
    cin >> N >> X;
    vector<ll> pre(N+1);
    for (int i = 1; i <= N; ++i) cin >> pre[i];
    sort( all(pre) );

    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        ll &r = pre[i];
        r += pre[i-1];
        if (X < r) continue;
        ans += max(0ll, (X-r)/i+1);
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
