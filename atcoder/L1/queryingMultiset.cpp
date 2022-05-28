// https://atcoder.jp/contests/abc212/tasks/abc212_d
// store priority separately, build prefix sum as we go
// binary search prefix sum
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using ll = long long;
using namespace std;

#define  tl(x) array<ll, x>
#define all(x) begin(x), end(x)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int Q; cin >> Q;

    ll cur = 0;
    priority_queue<tl(3)> pq;
    vector<tl(2)> pre = { {0,0} };
    for (ll p, x, q=1; q <= Q; ++q) {
        cin >> p;
        if (p == 1) {
            cin >> x;
            p = -(x-cur);
            pq.push( {p,x,q} );
        }
        if (p == 2) {
            cin >> x;
            cur += x;
            pre.push_back( {q,cur} );
        }
        if (p == 3) {
            auto [_,y,i] = pq.top();
            tl(2) tmp = {i,-1};
            auto [a,b] = *prev(upper_bound( all(pre), tmp ));
            auto [j,z] = pre.back();
            y += z - b;
            cout << y << '\n';
            pq.pop();
        }
    }
}
