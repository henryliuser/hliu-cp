#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll sum(ll x) {
    ll a = x, b = x+1;
    if (a%2) b /= 2ull;
    else a /= 2ull;
    return a*b;
}

bool check(ll g, ll k, ll x) {
    ll y = 0;
    // ll f = 2*k-1;
    // ll num = g / f;
    // ll full = sum(k) + sum(k-1);
    // ll y = full * num;
    // g %= f;
    if (g <= k) {
        y += sum(g);
    }
    if (g > k) {
        ll q = sum(k);
        ll p = sum(k-1);
        ll d = g - k;
        ll o = k - d - 1;
        ll w = sum(o);
        y += q + p - w;
        // printf("%lld %lld %lld %lld %lld %lld\n", q,d,o,p,w,y);
    }
    // printf("%lld\n", y);
    return y >= x || (g==2*k-1);
}

ll solve() {
    ll k, x; cin >> k >> x;
    ll lo = 1, hi = 2*k;
    while (lo < hi) {
        ll mid = lo + (hi-lo) / 2;
        if (check(mid, k, x)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    // check(1, 1, 2);
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";
}
