// https://codeforces.com/contest/1659/problem/C
// you're going to move the capital some number of times,
// iterate on that. When moving capital, always best to move it asap
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

struct DistSum {
    vector<ll> d[2], p[2];  // 0 left->right, 1 right->left
    DistSum(vector<ll> &a) {
        int n = a.size();
        for (int i : {0,1}) d[i].assign(n,0), p[i].assign(n,0);
        for (int i = 1; i < n; ++i) {
            d[0][i] = a[i] - a[i-1] + d[0][i-1];    // psum of dists
            p[0][i] = d[0][i] + p[0][i-1];  // psum of psum of dists
            d[1][n-i-1] = a[n-i] - a[n-i-1] + d[1][n-i];
            p[1][n-i-1] = d[1][n-i-1] + p[1][n-i];
        }
    }
    inline ll operator() (int src, int i) {
        int q = (src > i);
        ll diff = p[q][i] - p[q][src];
        ll cut = d[q][src];
        ll len = abs(src-i);
        return diff - cut * len;
    }
};

ll solve() {
    ll N, a, b;
    cin >> N >> a >> b;
    vector<ll> A(N+1);
    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    ll cur = 0;
    DistSum ds(A);
    ll ans = b * ds(0, N);
    for (int i = 1; i < N; ++i) {  // capital ends at i-th kingdom
        ll dx = A[i] - A[i-1];
        cur += (a+b) * dx;
        ll q = b * ds(i, N);
        ans = min(ans, cur + q);
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
