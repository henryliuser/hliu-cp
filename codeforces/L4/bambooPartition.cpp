#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static constexpr int MXN = 101;
static constexpr int MSQ = 31630;  // sqrt(1e9)
static constexpr int MXU = MXN * 2 * MSQ + 10;

vector<ll> A;
ll N, K, U = 0;
ll C = 0, uqd[MXU];   // store all unique denominator candidates

inline ll ceilSum(ll q) {
    ll k = 0;
    for (ll &x : A)
        k += (x+q-1)/q;
    return k;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;

    C = K;
    A.resize(N);
    for (ll &x : A) {
        cin >> x;
        C += x;
        for (int i = 1; i*i <= x; ++i) {
            uqd[U++] = i;
            uqd[U++] = (x + i-1) / i;
        }
    }

    ll ans = 0;
    sort(uqd, uqd+U);
    U = unique(uqd, uqd+U) - uqd;
    uqd[U] = 1e12+500;
    for (int i = 0; i < U; ++i) {
        ll q = uqd[i], r = uqd[i+1];  // between d = q and d = r
        ll cs = ceilSum(q);  // ALL VALUES OF cs ARE THE SAME.
        ll lo = q-1, hi = r;
        while (lo < hi) {
            ll mid = lo + (hi-lo+1) / 2;
            if (mid * cs <= C) lo = mid;
            else hi = mid - 1;
        }
        if (q <= lo && lo < r)
            ans = max(ans, lo);
    }
    cout << ans << "\n";
}

// this also passes, 1622 ms binary search vs 779 ms Math way above
//
// inline bool check(ll d) {
//     ll k = 0;
//     for (ll &x : A)
//         k += (x+d-1) / d * d - x;
//     return k <= K;
// }
// for (int i = 0; i < U; ++i) {
//     ll q = uqd[i], r = uqd[i+1];
//     ll lo = q-1, hi = r;
//     while (lo < hi) {
//         ll mid = lo + (hi-lo+1) / 2;
//         if (check(mid)) lo = mid;
//         else hi = mid - 1;
//     }
//     if (q <= lo && lo < r)
//         ans = max(ans, lo);
// }
