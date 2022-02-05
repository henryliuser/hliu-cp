// https://atcoder.jp/contests/abc238/tasks/abc238_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve() {
    ll A, S;
    cin >> A >> S;
    for (ll b = 0; b < 61; ++b) {
        ll bit = (1ll << b);
        if (A & bit) S -= (bit << 1);
        if (S < 0) return "No";
    }
    if (S & A) return "No";
    else return "Yes";
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        cout << solve() << '\n';
}
