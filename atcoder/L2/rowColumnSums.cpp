// https://atcoder.jp/contests/arc133/tasks/arc133_c
// read the editorial. I guess it's quite clever.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll H, W, K;
ll c = 0, d = 0;
ll sa = 0, sb = 0;
void add(ll &x, ll y) { x = (x+y) % K; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> H >> W >> K;
    ll mx = H * W * (K-1);
    vector<ll> A(H), B(W);
    for (ll &x : A) { cin >> x; add(sa, x); }
    for (ll &x : B) { cin >> x; add(sb, x); }
    if (sa != sb) goto bad;

    for (int i = 0; i < H; ++i)
        c += (W*(K-1) % K - A[i] + K) % K;
    for (int i = 0; i < W; ++i)
        d += (H*(K-1) % K - B[i] + K) % K;

    cout << mx - max(c, d) << '\n';
    return 0;

    bad:
    cout << -1 << '\n';
}
