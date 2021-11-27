#include <bits/stdc++.h>
using namespace std;
using tup = array<int, 2>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int ans = 0;
    int N, K; cin >> N >> K;
    vector<tup> A(N);
    for (tup& t: A) cin >> t[1] >> t[0];

    sort(begin(A), end(A));
    vector<int> ends(N), dp(N);
    for (int i = 0; i < N; ++i)
        ends[i] = A[i][0];

    // sort(begin(A), end(A), [](auto &a, auto &b)
    //     { return a[1] < b[1]; });
    for (auto pm : ends) cout << pm << " "; cout << endl;
    for (int i = 0; i < N; ++i) {
        dp[i] = 1;
        if (!i) continue;
        dp[i] = max(dp[i], dp[i-1]);
        int st = A[i][1];
        int j = lower_bound(begin(ends), end(ends), st) - begin(ends);
        if (--j < 0) continue;
        dp[i] = max(dp[i], 1 + dp[j]);
        ans = max(ans, dp[i]);
        for (auto pm : dp) cout << pm << " "; cout << endl;
    }
    cout << ans << "\n";

}
