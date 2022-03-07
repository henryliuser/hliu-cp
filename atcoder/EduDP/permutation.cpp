// https://atcoder.jp/contests/dp/tasks/dp_t
// dp[i][x] = # valid seqs ending in x using s[:i]
// we can imagine swapping out the current value and the relative order for
// 1 < 3 > 2 > x
// 2 < 4 > 3 > 1   # valid
// 1 < 4 > 3 > 2   # valid
// 1 < 4 > 2 > 3   # invalid
// the remaining ones can stay the same, since we process numbers in increasing order
// prefix sum each row of dp to compute the next one
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const ll Q = 1e9+7;

ll dp[2][3001];
void add(ll &x, ll y) { (x+=y)%=Q; }
ll dif(ll x, ll y) { return (x-y+Q)%Q; }

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    string S; cin >> S;

    dp[1][1] = 1;
    for (int i = 2; i <= N; ++i) {
        int t = i % 2;
        char cmp = S[i-2];
        for (int x = 1; x <= i; ++x)
            add(dp[!t][x], dp[!t][x-1]);
        if (cmp == '>')
            for (int x = 1; x <= i; ++x)
                dp[t][x] = dif(dp[!t][i], dp[!t][x-1]);
        if (cmp == '<')
            for (int x = 1; x <= i; ++x)
                dp[t][x] = dp[!t][x-1];
    }
    ll ans = 0;
    for (int x = 1; x <= N; ++x)
        add(ans, dp[N%2][x]);
    cout << ans << '\n';
}
