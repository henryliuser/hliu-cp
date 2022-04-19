// https://cses.fi/problemset/task/1650/
// can kill it with seg/sparse but intended sol:
// prefix sum for each bit then check parities.
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;
    vector<array<int,32>> P(N+1);
    for (int x, i=1; i <= N; ++i) {
        cin >> x;
        for (int b = 0; b < 32; ++b) {
            P[i][b] = P[i-1][b];
            if (x & (1<<b))
                ++P[i][b];
        }
    }

    for (int l,r, i=0; i < Q; ++i) {
        int res = 0;
        cin >> l >> r;
        auto &L = P[l-1];
        auto &R = P[r];
        for (int b = 0; b < 32; ++b) {
            int x = R[b] - L[b];
            res |= (x%2 << b);
        }
        cout << res << '\n';
    }
}
