// http://www.usaco.org/index.php?page=viewproblem2&cpid=862
// use map + PIE to avoid double counts
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
#define tl(x) array<ll, x>
using cow = tl(5);

ll N;
map<cow, ll> cnt;

ll pie(cow &x) {
    ll r[5] = {};
    for (int m = 1; m < 32; ++m) {
        int n = 0;
        cow cur = {-1,-1,-1,-1,-1};
        for (int b = 0; b < 5; ++b)
            if (m & (1<<b))
                cur[n++] = x[b];
        r[n-1] += cnt[cur]++;
    }
    return r[0] - r[1] + r[2] - r[3] + r[4];
}

int main() {
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);

    cow cur;
    cin >> N;
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        for (ll &x : cur) cin >> x;
        sort(begin(cur), end(cur));
        ans += pie(cur);
    }
    ll tot = N * (N-1) / 2;
    cout << tot - ans << '\n';
}
