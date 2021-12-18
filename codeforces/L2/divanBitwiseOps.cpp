// https://codeforces.com/contest/1614/problem/C
// nice question. sad i couldn't solve in time.
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

    while (M--) {
        int L, R, X;
        cin >> L >> R >> X;
        for (int i = 0; i < 32; ++i) {
            if (X & (1 << i)) continue;
            ++A[L-1][i];  // store bounds then psum
            --A[R][i];
        }
    }

    // run prefix sum
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 32; ++j)
            A[i][j] += A[i-1][j];
    }

    // construct original array
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 32; ++j) {
            if (A[i][j] <= 0)
                og[i] |= (1 << j);
        }
    }

    // sum of xor of all subsets
    ll b = 0;
    for (int i = 0; i < N; ++i)
        b |= og[i];
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
