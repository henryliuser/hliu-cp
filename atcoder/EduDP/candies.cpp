// https://atcoder.jp/contests/dp/tasks/dp_m
// for loop in dfs <=> prefix sum in tabulation
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll Q = 1e9+7;

int N, K;
vector<int> A;
ll dp[101][100001] = {};
ll add(ll x, ll y) { return ((x+=y) >= Q) ? x-Q : (x < 0) ? x+Q : x; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K; A.resize(N);
    vector<ll> A(N), pre(K+2);
    for (ll &x : A) cin >> x;

    for (int c = 0; c <= K; ++c)
        dp[N-1][c] = (K-c) <= A[N-1];

    for (int i = N-2; i >= 0; --i) {
        pre[0] = 0;
        for (int c = 0; c <= K; ++c)
            pre[c+1] = add(pre[c], dp[i+1][c]);
        for (int c = 0; c <= K; ++c) {
            ll j = min(0ll+K, A[i]+c);  // psum up to j
            ll dx = add(pre[j+1], -pre[c]);
            dp[i][c] = add(dp[i][c], dx);
        }
    }
    cout << dp[0][0] << '\n';
}
