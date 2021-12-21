// https://codeforces.com/problemset/problem/1556/C
// not sure how to come up with this myself.
// errichto explanation: https://www.youtube.com/watch?v=AbeEJvmsx0E
// especially the neighbor edge case is strange.
// cool problem anyway
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll ans = 0;
    int n; cin >> n;
    vector<ll> pre(n+1);
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        pre[i+1] = pre[i] + ( (i%2) ? -x : x );
    }

    for (int i = 0; i <= n; i += 2) {
        ll minBal = LLONG_MAX;
        for (int j = i+1; j <= n; ++j) {
            if (j%2==0) {
                ll m = max(pre[i], pre[j]);
                ll nxt = j != i+2;
                ans += max(0ll, minBal - m + nxt);
            }
            minBal = min(minBal, pre[j]);
        }
    }
    cout << ans << "\n";
}
