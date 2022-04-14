// https://codeforces.com/problemset/problem/1549/D
// my recursive seg tree TLE's
// use sparse table or iterative
// compute absolute value of adjacent differences D
// for each i binary search backwards/forwards for max subarray
// such that gcd( D[l..r] ) > 1
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using ll = long long;
using pll = array<ll, 2>;
const ll INF = 1e18+5;

inline ll gcd(ll a, ll b) {
    while (b)
        swap(a %= b, b);
    return a;
}

struct SparseTable {
    int N, K;
    vector<vector<ll>> T;
    int msb(int x) {  // log2(x) in O(1)
        union { double a; int b[2]; };
        a = x;
        return (b[1] >> 20) - 1023;
    }
    SparseTable (vector<ll> &A) {
        N = A.size();
        K = msb(N) + 1;
        T.assign(N, vector<ll>(K+1));
        for (int i = 0; i < N; ++i)
            T[i][0] = A[i];
        for (int j = 1; j <= K; ++j)
            for (int i = 0; i <= N-(1<<j); i++)
                T[i][j] = gcd(T[i][j-1], T[i+(1<<(j-1))][j-1]);  // adjust
    }
    ll query(int l, int r) {
        ll res = 0;  // adjust
        for (int i = K; ~i; --i)
            if (l+(1<<i)-1 <= r) {
                res = gcd(res, T[l][i]);  // adjust
                l += (1<<i);
            }
        return res;
    }
};

int solve() {
    int N; cin >> N;
    vector<ll> A(N), D(N);
    for (ll &x : A) cin >> x;
    for (int i = 1; i < N; ++i)
        D[i] = abs(A[i] - A[i-1]);

    int ans = 1;
    SparseTable st(D);
    for (int i = 1; i < N; ++i) {
        int l = 1, r = i+1;
        while (l < r) {
            int m = (l+r)/2;
            ll g = st.query(m, i);
            if (g == 1) l = m+1;
            else r = m;
        }
        ans = max(ans, i-l+2);
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
