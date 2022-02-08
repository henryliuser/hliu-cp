// https://atcoder.jp/contests/abc236/tasks/abc236_f
// MST + knapsack dp, pretty good concept actually
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pi(x) array<int, x>

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    int p = (1 << N) - 1;
    vector<pi(2)> A(p);
    for (int i = 0; i < p; ++i) {
        cin >> A[i][0];
        A[i][1] = i+1;
    }
    ll ans = 0;
    vector<bool> dp(p+1);
    sort(begin(A), end(A));
    for (int i = 0; i < p; ++i) {
        int x = A[i][1];
        int c = A[i][0];
        if (dp[x]) continue;
        ans += c;
        for (int j = 0; j <= p; ++j)
            if (dp[j])
                dp[j ^ x] = 1;
        dp[x] = 1;
    }
    cout << ans << '\n';
}
