// https://codeforces.com/contest/1706/problem/D1
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ti = array<int, 3>;

int solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n);
    for (int &x : A) cin >> x;

    multiset<ti> ms;
    for (int x : A)
        ms.insert( {x,x,1} );

    int ans = 1e9+5;
    while (1) {
        auto it1 = prev(end(ms));
        auto it2 = prev(it1);
        auto [minQ, _, __] = *ms.begin();
        auto [q1,n1,d1] = *it1;
        ans = min(ans, q1 - minQ);
        if (d1 == k) break;
        ms.erase(it1);
        ms.insert( {n1/(d1+1), n1, d1+1} );
    }
    return ans;
}

signed main() {
    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}
