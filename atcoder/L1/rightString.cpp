// https://atcoder.jp/contests/arc140/tasks/arc140_a
// try all factors and take majority
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

int N, K;
string S;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K >> S;

    int ans = N;
    for (int sz = 1; sz < N; ++sz) {
        if (N % sz != 0) continue;
        int M = N / sz;
        int res = 0;
        for (int i = 0; i < sz; ++i) {
            int cnt[26] = {};
            for (int j = i; j < N; j += sz)
                ++cnt[ S[j]-'a' ];
            res += M - *max_element(cnt, cnt+26);
        }
        if (res > K) continue;
        ans = sz;
        break;
    }

    cout << ans << '\n';
}
