// https://codeforces.com/contest/1614/problem/C
// ..........
// ...
// ...
// math.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using bits = array<int, 32>;
const int MOD = 1e9 + 7;

// fast modular exponentiation
ll modPow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int solve() {
    int N, M;
    cin >> N >> M;
    vector<ll> og(N);
    vector<bits> A(N+1);

    int b = 0;
    while (M--) {
        int L, R, X;
        cin >> L >> R >> X;
        b |= X;
    }
    ll ans = (b * modPow(2, N-1, MOD)) % MOD;
    return ans;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";
}
