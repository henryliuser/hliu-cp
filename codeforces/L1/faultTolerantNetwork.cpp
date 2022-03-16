// https://codeforces.com/contest/1651/problem/C
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using pl = array<ll, 2>;
const ll inf = 1e18;
#define all(x) (x).begin(), (x).end()

ll close(set<ll> &t, ll x) {
    auto it = t.lower_bound(x);
    if (it == end(t)) --it;
    ll c = abs(x - *it);
    if (it != begin(t)) --it;
    ll d = abs(x - *it);
    return min(c,d);
}

ll solve() {
    int N; cin >> N;
    vector<ll> A(N), B(N);
    for (ll &x : A) cin >> x;
    for (ll &x : B) cin >> x;
    set<ll> sa( all(A) );
    set<ll> sb( all(B) );
    
    ll a = A[0], b = A[N-1];
    ll c = B[0], d = B[N-1];

    ll q1 = abs(a-c) + abs(d-b);
    ll q2 = abs(a-d) + abs(b-c);
    ll ca = close(sb, a);
    ll cb = close(sb, b);
    ll cc = close(sa, c);
    ll cd = close(sa, d);
    ll q3 = abs(a-c) + cb + cd;
    ll q4 = abs(b-d) + ca + cc;
    ll q5 = abs(a-d) + cc + cb;
    ll q6 = abs(b-c) + ca + cd;
    ll q7 = ca + cb + cc + cd;
    return min( {q1, q2, q3, q4, q5, q6, q7} );
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
