// https://atcoder.jp/contests/abc246/tasks/abc246_f
// just PIE
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const ll Q = 998244353;

int N, L;
int S[19] = {};

void add(ll &a, ll b) { a=((a+b)%Q+Q)%Q; }

ll modPow(ll a, ll b) {
    a %= Q;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % Q;
        a = a * a % Q;
        b >>= 1;
    }
    return res;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll ans = 0;
    cin >> N >> L;
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        for (char c : s)
            S[i] |= (1 << (c-'a'));
    }
    int p = pow(2, N);
    for (int m = 1; m < p; ++m) {
        int cs = INT_MAX;  // cs = 11111... full mask
        int sz = __builtin_popcount(m);
        for (int b = 0; b < N; ++b)
            if (m & (1<<b))
                cs &= S[b];

        ll j = __builtin_popcount(cs);  // number of shared chars in subset m
        ll x = modPow(j, L);
        ll s = (sz%2) ? 1 : -1;  // pie sign
        add(ans, s * x);
    }
    cout << ans << '\n';
}
