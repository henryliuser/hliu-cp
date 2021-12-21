// https://atcoder.jp/contests/arc130/tasks/arc130_b
// maintain row/col -> color -> line count record
// on update, clear the t_i dict and adjust the corresponding

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using qry = array<ll, 3>;

int main() {
    int H, W, C, Q;
    cin >> H >> W >> C >> Q;
    vector<qry> queries;
    while (Q--) {
        ll t, n, c;
        cin >> t >> n >> c;
        queries.push_back({t,n,c});
    }

    ll rc = 0, cc = 0;
    unordered_map<int, ll> cnt;
    unordered_map<int, bool> seen[3];
    reverse(begin(queries), end(queries));
    for (qry &q : queries) {
        auto [t,n,c] = q;
        if (t == 1) {
            if (seen[t][n]) continue;
            seen[t][n] = true;
            cnt[c] += W - cc;
            ++rc;
        }
        if (t == 2) {
            if (seen[t][n]) continue;
            seen[t][n] = true;
            cnt[c] += H - rc;
            ++cc;
        }
    }

    for (int i = 1; i <= C; ++i)
        cout << cnt[i] << " ";
    cout << "\n";

}
