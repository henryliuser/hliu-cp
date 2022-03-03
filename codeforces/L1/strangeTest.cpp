// https://codeforces.com/contest/1632/problem/C
// (a | b) >= b
// intuitive try min of 2:
// a++ ... a|b, b++
// b++ ... a|b, b++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    int a, b;
    cin >> a >> b;
    ll ans = b-a;
    for (int c = a; c <= b; ++c) {
        ll v = (c-a) + (c|b) - b + 1;
        ans = min(ans, v);
    }
    int lim = b*2+1;
    for (int d = b; d <= lim; ++d) {
        ll v = (d-b) + (a|d) - d + 1;
        ans = min(ans, v);
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
