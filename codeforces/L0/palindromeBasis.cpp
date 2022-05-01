// https://codeforces.com/contest/1673/problem/C
#include <bits/stdc++.h>
using namespace std;
const int MXN = 4e4+1;
const int Q = 1e9+7;

int dp[MXN] = {};

int main() {
    dp[0] = 1;
    cin.tie(0)->sync_with_stdio(0);
    for (int y = 1; y < MXN; ++y) {
        string s = to_string(y);
        string t = to_string(y);
        reverse(all(t));
        if (s != t) continue;  // only like 500 palindromes under 4e4
        for (int x = 0; x+y < MXN; ++x) {
            if (dp[x])
                dp[x+y] = (dp[x+y] + dp[x]) % Q;
        }
    }

    int n, t; cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }

}
