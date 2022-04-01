#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

int N;
string S;

ll solve() {
    int ans = 0;
    cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        int p = 0, m = 0, c = 0, l = -1;
        for (int j = i; j < N; ++j) {
            if (S[j] == '+') ++p;
            if (S[j] == '-') {
                ++m;
                if (j > i && S[j] == S[j-1] && j-1 > l) {
                    l = j;
                    ++c;
                }
            }
            int dx = m - p;
            bool can = (dx > 0 && dx%3 == 0 && c >= dx/3);
            ans += (p == m || can);
        }
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
