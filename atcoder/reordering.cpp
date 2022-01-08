#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using cnt = array<ll, 26>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s; cin >> s;
    int N = s.size();
    vector<vector<ll>> dp(N+1, vector<ll>(26));
    for (int i = 0; i < N; ++i) {
        int x = s[i] - 'a';
        for (int len = 1; len <= N; ++len) {
            dp[len]
        }
    }
}
