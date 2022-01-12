#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    while (b)
        swap(a %= b, b);
    return a;
}

int N;
vector<ll> A;

ll check(ll odd) {
    ll g = A[odd];
    for (int i = 2+odd; i < N; i += 2)
        g = gcd(g, A[i]);
    for (int i = !odd; i < N; i += 2)
        if (A[i] % g == 0)
            return 0;
    return g;
    // for (ll f : factorize(g)) {
    //     for (int i = !odd; i < N; i += 2)
    //         if (A[i] % f == 0)
    //             goto bad;
    //     return f;
    //     bad: continue;
    // }
    // return 0;
}

ll solve() {
    cin >> N; A.resize(N);
    for (ll &x : A) cin >> x;

    ll evens = check(0);
    if (evens) return evens;
    ll  odds = check(1);
    if  (odds) return odds;
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
