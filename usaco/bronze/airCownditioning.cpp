#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// find the longest prefix of all positive or all negative
// compute the minimum ops to make 0 greedily
// if dx == 0 or dx flips signs, restart on new segment
int main() {
    ll N; cin >> N;
    vector<ll> A(N), B(N);
    for (ll &x : A) cin >> x;
    for (ll &x : B) cin >> x;

    ll ans = 0, ch = 0;
    for (int i = 0; i < N; ++i) {
        ll dx = A[i] - B[i];
        if (ch <= 0 && dx > 0) ans += dx;
        else if (ch <= 0 && dx < 0 && dx < ch) ans += abs(dx-ch);
        else if (ch >= 0 && dx < 0) ans -= dx;
        else if (ch >= 0 && dx > 0 && dx > ch) ans += abs(dx-ch);
        ch = dx;
    }

    cout << ans << '\n';
}
