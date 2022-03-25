// https://codeforces.com/problemset/problem/1657/C
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

int N;
string S;

int bal, bust, pst;
bool ok(int x) {
    if (!bust) {
        bal += (x) ? -1 : 1;
        bust |= (bal < 0);
        if (!bust && !bal) return 1;
    }
    if (x == pst) return 1;
    return 0;
}
void reset(int x) {
    bal = (x) ? -1 : 1;
    bust = (bal < 0), pst = x;
}

void solve() {
    cin >> N >> S;
    int ops = 0;
    int rem = N;

    reset( S[0]-'(' );
    for (int i = 1; i < N; ++i) {
        int c = S[i] - '(';
        if (ok(c)) {
            ++ops;
            rem = N-i-1;
            if (i+1 < N)
                reset(S[++i]-'(');
        }
    }
    cout << ops << " " << rem << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
