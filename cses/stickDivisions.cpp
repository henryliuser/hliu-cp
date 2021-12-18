#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll x, n; cin >> x >> n;
    priority_queue<ll> pq;
    while (n--) {
        ll y; cin >> y;
        pq.push(-y);
    }
    ll res = 0;
    while (!pq.empty()) {
        ll p = pq.top(); pq.pop();
        if (-p == x) break;
        ll q = pq.top(); pq.pop();
        res -= p + q;
        pq.push(p+q);
    }
    cout << res << "\n";
}
