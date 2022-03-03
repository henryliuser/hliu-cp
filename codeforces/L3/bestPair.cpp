// https://codeforces.com/problemset/problem/1637/E
// only O(sqrt(N)) unique values of cnt
// double loop on cx and cy
// try every x with the max y that is valid [x!=y, (x,y) not forbidden]
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll solve() {
    cin >> N >> M;
    map<ll, ll> cnt;
    vector<ll> A(N);
    for (ll &x : A) {
        cin >> x;
        ++cnt[x];
    }
    set<array<ll,2>> bad;
    for (int i = 0; i < M; ++i) {
        int x, y; cin >> x >> y;
        bad.insert({x,y});
        bad.insert({y,x});
    }

    vector<vector<ll>> occ(N+1);
    for (auto &[x,c] : cnt)
        occ[c].push_back(x);  // x's are sorted

    ll ans = 0;
    for (ll cx = 1; cx <= N; ++cx)
        for (ll x : occ[cx])
            for (ll cy = 1; cy <= cx; ++cy) {
                auto &v = occ[cy];
                int j = v.size();
                while (j--) {  // process backwards, take first one that works
                    ll y = v[j];
                    if (x == y) continue;
                    if (bad.count({x,y})) continue;
                    ll q = (cx+cy) * (x+y);
                    ans = max(ans, q);
                    break;  // stop at the first one
                }
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
