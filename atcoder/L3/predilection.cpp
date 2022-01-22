// https://atcoder.jp/contests/abc230/tasks/abc230_f
// trick is to realize that you only need the rightmost j
// such that pre[j+1] = pre[i-1]; 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MXN = 2e5+2;
const ll MOD = 998244353;

ll dp[MXN] = {};
// dp[i] = # of unique resulting seqs in A[:i]

void add(ll &x, ll y) { x = (x+y+MOD) % MOD; }
ll mul(ll x, ll y) { return (x*y+MOD) % MOD; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    vector<ll> A(N);
    for (ll &x : A) cin >> x;

    dp[1] = 1;
    ll cur = A[1];
    map<ll, ll> mp;
    for (int i = 2; i <= N; ++i) {
        dp[i] = mul(dp[i-1], 2);
        if (mp.count(cur)) {
            int j = mp[cur] - 1;
            if (j >= 0)
                add(dp[i], -dp[j]);
        }
        mp[cur] = i;
        cur += A[i-1];
        // add(cur, A[i-1]);  this line stumped me for 3 hours.
    }

    cout << dp[N] << '\n';

}
