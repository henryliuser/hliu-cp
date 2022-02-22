// https://atcoder.jp/contests/abc231/tasks/abc231_e
// only 2 choices to make at each point.
// start from the back, do it greedily
// for each d in A, either use X/d or (X/d)+1
// on the change side, you don't need to DP, just greedy.
// ...
// ...
// ok i don't actually understand why this works yet
// investigate later
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = array<ll, 2>;

ll N, X;
map<pl, ll> dp;
vector<ll> A;

ll dfs(ll i, ll c) {
    if (i == -1) return 0;
    pl t = {i,c};
    if (dp.count(t)) return dp[t];
    ll &res = dp[t];
    ll q = c / A[i];
    ll a = q + dfs(i-1, c - q*A[i]);
    ll b = q+1 + dfs(i-1, q*A[i]+A[i] - c);
    res = min(a,b);
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> X;
    A.resize(N);
    for (ll &x : A) cin >> x;

    cout << dfs(N-1, X) << '\n';
}
