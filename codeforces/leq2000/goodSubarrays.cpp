// https://codeforces.com/contest/1398/problem/C
#include <bits/stdc++.h>
using namespace std;

int solve() {
    int ans = 0;
    int n; cin >> n;
    string v; cin >> v;
    vector<int> dp(n+1), pre(n+1);
    for (int i = 1; i <= n; ++i) {
        int x = v[i-1] - '0';
        pre[i] = pre[i-1] + x;
        if (x == 1) dp[i] = 1;
        if (x <= i) {
            int ps = pre[i] - pre[i-x];
            if (ps <= i)
                dp[i] += dp[i-ps];
        }
        ans += dp[i];
    }
    for (auto x : dp) printf("%d ", x); cout << endl;
    for (auto x : pre) printf("%d ", x); cout << endl;
    return ans;
}

int main() {

    int t; cin >> t;
    while (t--)
        cout << solve() << endl;

}
