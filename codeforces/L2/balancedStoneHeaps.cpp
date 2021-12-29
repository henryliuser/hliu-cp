// https://codeforces.com/contest/1623/problem/C
// fun problem. Work backwards, do greedy.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<ll> A;
ll check(ll g) {
    vector<ll> B = A;
    for (int i = N-1; i >= 2; --i) {
        ll can = max(0ll, min(A[i], B[i]-g));
        ll d = can/3;
        B[i] -= d*3;
        B[i-1] += d;
        B[i-2] += d*2;
    }
    return *min_element(begin(B), end(B));
}

ll solve() {
    cin >> N; A.resize(N);
    ll lo = 1e18, hi = 1e18;
    for (ll &x : A) {
        cin >> x;
        lo = min(lo, x);
    }
    while (lo < hi) {
        ll mid = lo + (hi-lo+1) / 2;
        ll c = check(mid);
        if (c >= mid) lo = c;
        else hi = mid-1;
    }
    return lo;

}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << "\n";
}
