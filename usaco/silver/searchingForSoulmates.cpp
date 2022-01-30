#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define F first
#define S second

ll solve() {
    ll ans = 1e18;
    ll A, B; cin >> A >> B;
    if (A == B) return 0;

    ll MX = max(A, B);
    map<ll,ll> p2 = { {B,0} };  // factors of B where divisor is power of 2
    // store sorted factors and pre-computed distance from B

    ll i = 0, q = B;
    while (q < MX) p2[q*=2] = ++i;
    i = 1, q = B;
    while (q >= 1) {
        if (q%2) {
            p2[q-1] = i;
            if (q != 1) p2[(q-1)/2] = i+1;
            q = (q-1)/2, ++i;
        }
        else p2[q/=2] = i;
        ++i;
    }

    i = 0, q = A;
    while (q < B) {
        auto p = p2.upper_bound(q);
        ll pos  = p->F;
        ll dist = p->S;
        ans = min(ans, pos-q + dist + i);
        q *= 2;
        ++i;
    }

    i = 0, q = A;
    while (q > 0) {
        auto p = p2.upper_bound(q);
        ll pos  = p->F;
        ll dist = p->S;
        ans = min(ans, pos-q + dist + i);
        if (q % 2) {
            if ((q+1)/2 == q) break;  // lol
            q = (q+1)/2;
            ++i;
        }
        else q /= 2;
        ++i;
    }
    return ans;
}

int main() {
    int N; cin >> N;
    while (N--)
        cout << solve() << '\n';
}
