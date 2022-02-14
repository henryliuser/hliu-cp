// code blast thing
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> solve() {
    ll n, l, r, s;
    cin >> n >> l >> r >> s;
    set<ll> xs;
    vector<ll> res;
    for (int i = 1; i <= n; ++i)
        xs.insert(i);
    int sz = r - l + 1;
    while (xs.size() && s > 0 && sz--) {
        auto it = xs.lower_bound(s);
        if (it == end(xs)) --it;
        s -= *it;
        res.push_back(*it);
        xs.erase(it);
    }
    if (s != 0) return {};
    vector<int> ans(n);
    for (int i = 1; i <= n; ++i) {
        if (l <= i && i <= r) {
            ans[i] = res.back();
            res.pop_back();
            continue;
        }
        auto it = xs.begin();
        ans[i] = *it;
        xs.erase(it);
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        auto s = solve();
        if (s.empty()) cout << -1 << '\n';
        else {
            for (int x : s) cout << x << " ";
            cout << '\n';
        }
    }
}
