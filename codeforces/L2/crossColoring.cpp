// https://codeforces.com/contest/1644/problem/D
// process qaueries in reverse. this way we know whether or not
// a cell-query is relevant, or if it will be completely overwritten afterwards anyways
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll Q = 998244353;
#define tl(x) array<ll, x>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

void mult(ll &a, ll b) { a = (a*b)%Q; }

ll solve() {
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;

    int x, y;
    ll ans = 1;
    set<int> xs, ys;
    vector<tl(2)> qry(Q);
    for (auto &q : qry)
        cin >> q[0] >> q[1];

    while (Q--) {
        int x = qry[Q][0];
        int y = qry[Q][1];
        if (xs.count(x) && ys.count(y)) continue;
        if (xs.size() == N) break;
        if (ys.size() == M) break;
        xs.insert(x), ys.insert(y);
        mult(ans, K);
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
