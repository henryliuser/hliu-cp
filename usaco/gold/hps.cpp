#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[100001];
int dp[100001][21][3];
int dfs(int i, int k, int m) {
    if (i == N) return 0;
    int &v = dp[i][k][m];
    if (v != -1) return v;
    v = (A[i] == m);
    int res = 0;
    for (int j = 0; j < 3; ++j)
        if (i != j && k > 0)
            res = max(res, dfs(i+1, k-1, j));
    res = max(res, dfs(i+1, k, m));
    v += res;
    return v;
}

int main() {
    memset(dp, -1, sizeof dp);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        if (s == "H") A[i] = 0;
        if (s == "P") A[i] = 1;
        if (s == "S") A[i] = 2;
    }
    int h = dfs(0, K, 0);
    int p = dfs(0, K, 1);
    int s = dfs(0, K, 2);
    cout << max({h, p, s}) << endl;


}
