// https://codeforces.com/problemset/problem/335/B
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

int N;
string S;
int dp[2601][2601];

void geq() {
    map<int, int> cnt;
    for (char c : S)
        if (++cnt[c] >= 100) {
            for (int i = 0; i < 100; ++i)
                cout << c;
            cout << '\n';
            return;
        }
}

void le() {
    for (int z = 1; z <= N; ++z) {
        for (int i = 1; i <= N; ++i) {
            dp[i+z]
        }
    }
}

int main() {
    memset(dp, 0, sizeof dp);
    cin.tie(0)->sync_with_stdio(0);

    cin >> S;
    N = S.size();
    if (N >= 2575) geq();
    else le();
}
