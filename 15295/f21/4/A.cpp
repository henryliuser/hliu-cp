#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> A, dp;
int dfs(int i) {
    if (i >= N) return 0;
    if (dp[i] != -1) return dp[i];
    dp[i] = A[i] + dfs(i + A[i]);
    return dp[i];
}

int solve() {
    cin >> N;
    A.resize(N);
    dp.assign(N, -1);
    int ans = 0;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < N; ++i)
        ans = max(ans, dfs(i));
    return ans;
}

int main() {
    int T; cin >> T;
    while (T--)
        cout << solve() << endl;
}
