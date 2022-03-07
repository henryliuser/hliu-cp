// https://atcoder.jp/contests/dp/tasks/dp_u
// 3 state bitmask - AT, T, NT
// already taken
// taken in current group
// not taken
// for each mask m, loop over subsets of set bits `z`
// `z ^ m` is the mask of the group that transitions from dp[z] to dp[m]
// total complexity O(3^N + 2^N * N^2)
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

ll dp[1<<16] = {};
ll score[1<<16] = {};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N));
    for (auto &L : A)
        for (ll &x : L)
            cin >> x;

    int p = (1<<N);
    for (int m = 0; m < p; ++m)
        for (int i = 0; i < N; ++i)
            if (m & (1<<i))
                for (int j = i+1; j < N; ++j)
                    if (m & (1<<j))
                        score[m] += A[i][j];

    dp[0] = 0;
    for (int m = 0; m < p; ++m) {
        dp[m] = score[m];
        for (int z = (m-1)&m; z > 0; z = (z-1)&m)    // loop over subsets of set bits
            dp[m] = max(dp[m], dp[z] + score[z^m]);  // z^m is the "new" group from old
    }
    cout << dp[p-1] << '\n';
}

// intuitive code
//
//    for (int m = 0; m < p; ++m) {  // m = mask of already taken
//        vector<int> nt;  // not taken
//        for (int i = 0; i < N; ++i) {
//            if (m & (1<<i)) continue;
//            nt.push_back(i);
//        }
//        int sz = nt.size();
//        int q = (1<<sz);
//        for (int z = 0; z < q; ++z) {
//            int w = 0;
//            for (int i = 0; i < sz; ++i) {
//                if (z & (1<<i))
//                    w |= (1 << nt[i]);
//            }
//            dp[m|w] = max(dp[m|w], dp[m] + score[w]);
//        }
//    }
