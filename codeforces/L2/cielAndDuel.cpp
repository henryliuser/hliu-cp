// https://codeforces.com/contest/321/problem/B
// if you can eliminate everything, then upper_bound def, lower_bound atk
//    reason for targeting def first, you want to minimize dmg wasted
// if you can't, run max against atk
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
multiset<ll> jiro;
vector<ll> atk, def;

ll tryAll() {
    ll res = 0;
    auto J = jiro;
    auto A = atk, D = def;
    for (int x : D) {
        auto it = J.upper_bound(x);
        if (it == end(J)) return 0;
        J.erase(it);
    }
    for (int x : A) {
        auto it = J.lower_bound(x);
        if (it == end(J)) return 0;
        res += *it - x;
        J.erase(it);
    }
    for (int x : J) res += x;
    return res;
}

ll tryGreedy() {
    ll res = 0;
    for (int x : atk) {
        if (jiro.empty()) return res;
        auto it = prev(end(jiro));
        if (*it < x) return res;
        res += *it - x;
        jiro.erase(it);
    }
    return res;
}

ll solve() {
    cin >> N >> M;
    while (N--) {
        string t; ll x;
        cin >> t >> x;
        if (t == "ATK") atk.push_back(x);
        if (t == "DEF") def.push_back(x);
    }
    sort(atk.begin(), atk.end());
    sort(def.begin(), def.end());
    while (M--) {
        int x; cin >> x;
        jiro.insert(x);
    }
    ll ans = tryAll();
    ans = max(ans, tryGreedy());
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << solve() << "\n";
}
