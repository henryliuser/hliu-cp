#include <bits/stdc++.h>
using namespace std;

const int Q = 998244353;
int main() {
    int N; cin >> N;
    vector<int> A(N), B(N);
    vector<vector<int>> dp;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    int t = B[0] - A[0] + 1;
    vector<int> curr(t, 1);
    vector<int> ps(t+1);
    for (int i = 0; i < t; ++i)
        ps[i+1] = ps[i] + curr[i];
    dp.push_back(ps);

    for (int c = 1; c < N; ++c) {
        int t = B[c] - A[c] + 1;
        curr = vector<int>(t);
        ps = vector<int>(t+1);
        int sz = dp[c-1].size();
        for (int j = A[c]; j <= B[c]; ++j) {
            int p = max(B[c-1] - j, 0);
            curr[j-A[c]] = dp[c-1][sz-p-1];
        }
        for (int i = 0; i < t; ++i)
            ps[i+1] = (ps[i] + curr[i]) % Q;
        dp.push_back(ps);
    }
    cout << dp[N-1].back() % Q << endl;

}
