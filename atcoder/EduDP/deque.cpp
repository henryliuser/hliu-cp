#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

vector<int> A;
ll dp[2][3001][3001];

ll dfs(bool p, int i, int j) {
    ll &res = dp[p][i][j];
    if (res != -1) return res;
    if (p  && i >= j) return A[i];
    if (!p && i >= j) return -A[i];

    ll a = dfs(!p, i+1, j);
    ll b = dfs(!p, i, j+1);
    if (p) res = max(a,b);
    else   res = min(a,b);
    return res;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    A.resize(N);
    for (int &x : A)
        cin >> x;

    cout << dfs(1, 0, N-1) << '\n';
}
