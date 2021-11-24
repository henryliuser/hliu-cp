// https://codeforces.com/problemset/problem/1612/C
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
    }
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
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";
}
