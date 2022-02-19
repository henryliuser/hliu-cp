// https://codeforces.com/problemset/problem/1634/B
// via investigation, all op sequences for alice lead to same parity
// all op sequences for bob lead to opposite parity
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve() {
    ll N, x, y;
    cin >> N >> x >> y;
    vector<ll> A(N);
    ll sum = x;
    for (ll &z : A) {
        cin >> z;
        sum += z;
    }
    return (sum%2 == y%2) ? "Alice" : "Bob";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
