// https://codeforces.com/contest/1619/problem/E
// fun question
// first compute the mex. let A[i] be count of occurrences of i
// for i < mex: ans[i] = A[i]
// for i = mex: ans[i] = 0
// for i > mex: ans[i] = A[i] + last + difference between xtra lower_bound
// if xtra required but is empty, ans[i...N] = -1
// last = ans[i] - A[i]; don't include the counts to get rid of current
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, last = 0;
bool flag = false;  // everything after is -1
map<ll, ll> A;
multiset<ll> xtra;

ll geq(int i) {
    if (flag) return -1;
    ll cnt = A[i];
    if (A[i-1]) return cnt + last;
    if (xtra.empty()) return -1;  // set flag to 1
    auto it = xtra.lower_bound(i-1);
    if (it == begin(xtra)) return -1;
    ll x = *(--it);
    xtra.erase(it);
    return cnt + last + (i-1-x);
}

void reset() {
    A.clear(); xtra.clear();
    flag = last = 0;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        ll x; cin >> x;
        if (A[x]++) xtra.insert(x);
    }
    ll mex = N;
    for (int i = 0; i < N; ++i)
        if (!A[i]) {
            mex = i;
            break;
        }

    for (int i = 0; i < mex; ++i)
        cout << A[i] << " ";

    cout << "0 ";
    for (ll i = mex+1; i <= N; ++i) {
        ll x = geq(i);
        if (x == -1) flag = true;
        last = x - A[i];
        cout << x << " ";
    }
    cout << "\n";

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        reset();
        solve();
    }
}
