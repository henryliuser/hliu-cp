// https://atcoder.jp/contests/abc252/tasks/abc252_f
// same as cses stick divisions, greedy huffman encoding tree thing
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using ll = long long;
using namespace std;

int main() {
    ll rem = 0;
    ll X, N;
    cin >> N >> X;
    vector<ll> A(N);
    for (ll &x: A) {
        cin >> x;
        rem += x;
    }
    ll ans = 0;
    priority_queue<ll> pq;
    if (rem != X) pq.push(-X+rem);
    for (ll x : A) pq.push(-x);
    while (!pq.empty()) {
        ll p = pq.top(); pq.pop();
        if (-p == X) break;
        ll q = pq.top(); pq.pop();
        ans -= p + q;
        pq.push(p + q);
    }
    cout << ans << '\n';
}
