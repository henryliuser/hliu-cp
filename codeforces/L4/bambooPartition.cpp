// https://codeforces.com/contest/830/problem/C
// really nice question, two solutions below.
// initial setup:
// A = [target heights]
// let cs(q) = sum( ceil(x/q) for x in A )
// maximize d such that " sum( ceil(x/d) * d - x for x in A ) <= K "
// rewrite/simplify summation:
// maximize d such that " d * cs(d) <= K + sum(A) "
// let C = K + sum(A)
// fixed number of unique values of ceil(x/q): O(sqrt(x)) of them
// compute all of the denominators of those unique values in O(N sqrt N)
// then find all of the unique such denominators
// these denominators form segments where ALL cs(q) for q in [L,R) ARE EQUAL!
// then, on these segments, the k value obtained is monotonic
// solution 1. (779 ms, AC)  take C / cs(q) = d, if q <= d < r, then it's good.
// solution 2. (1622 ms, AC) binary search  over each [L,R) for max value
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static constexpr int MXN = 101;
static constexpr int MSQ = 31630;  // sqrt(1e9)
static constexpr int MXU = MXN * 2 * MSQ + 10;

vector<ll> A;
ll N, K, U = 0;
ll C = 0, uqd[MXU];   // store all unique denominator candidates

ll ceilSum(ll q) {
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
        cin >> x; C += x;
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
        ll cs = ceilSum(q);     // ALL VALUES OF cs ARE THE SAME.
        ll d = C / cs;
        if (q <= d && d < r)
            ans = max(ans, d);
    }
    cout << ans << "\n";
}


// bool check(ll d) {
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
