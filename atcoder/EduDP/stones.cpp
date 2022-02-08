// https://atcoder.jp/contests/dp/tasks/dp_k
// if any of ur moves force opponent loss then u win, also memo
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, K, A[101];
int dp[2][100001] = {};

bool dfs(bool t, int k) {
    if (k <= 0) return 0;
    int &win = dp[t][k];
    if (win != -1) return win;

    win = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] > k) continue;
        if (!dfs(!t, k-A[i]))
            win = 1;
    }
    return win;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    memset(dp, -1, sizeof dp);
    bool ans = dfs(1, K);
    cout << ( ans ? "First\n" : "Second\n" );
}
