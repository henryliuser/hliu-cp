#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    int N; cin >> N;
    vector<ll> A(N);
    priority_queue<ll> pq;
    for (ll &x : A) {
        cin >> x;
        pq.push(-x);
    }
    ll ans = INT_MIN, cur = 0;
    while (!pq.empty()) {
        ll x = -pq.top();
        ans = max(ans, x-cur);
        cur = x;
        pq.pop();
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
