// https://codeforces.com/contest/1691/problem/C
// troll
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

int N, K;
string S;

int solve() {
    cin >> N >> K >> S;
    vector<int> ones;
    for (int i = 0; i < N; ++i)
        if (S[i] == '1')
            ones.push_back(i);

    int q = ones.size();
    switch (q) {
        case 0: return 0;
        case 1:
            if (N-ones[0]-1 <= K) return 1;
            if (ones[0] <= K) return 10;
            return 11;
        default:
            int i = ones[0], j = ones.back();
            if (i + N-j-1 <= K) return (q-1) * 11;
            if (N-j-1 <= K) return (q-1) * 11 + 1;
            if (i <= K) return (q-1) * 11 + 10;
            return q*11;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}
