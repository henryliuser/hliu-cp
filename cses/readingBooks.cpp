// https://cses.fi/problemset/task/1631
// math intuition.
// if max > sum - max, then it's just max * 2
// else it's just sum
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    vector<ll> A(N);
    for (ll &x : A) cin >> x;
    ll m = *max_element( all(A) );
    ll s = accumulate( all(A), 0ll );
    cout << max(s, 2ll*m) << '\n';
}
