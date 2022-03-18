// https://www.codechef.com/START30B/problems/MLIS
// pretty obvious. keep prefix LIS and do suffix LDS and take the best
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

ll solve() {
    int N; cin >> N;
    vector<int> A(N), dp[2];
    vector<int> lis(N);
    for (int &x : A) cin >> x;
    for (int i = 0; i < N; ++i) {
        auto it = lower_bound( all(dp[0]), A[i] );
        if (it == end(dp[0])) dp[0].push_back(A[i]);
        else *it = A[i];
        lis[i] = dp[0].size();
    }
    int ans = lis[N-1];
    for (int i = N-1; i > 0; --i) {
        auto it = lower_bound( all(dp[1]), -A[i] );
        if (it == end(dp[1])) dp[1].push_back(-A[i]);
        else *it = -A[i];
        int cur = dp[1].size();
        ans = max(ans, cur + lis[i-1]);
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
