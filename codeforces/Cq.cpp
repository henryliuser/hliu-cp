#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll N, H;
vector<ll> A;

bool check(ll g) {
    ll dmg = g;
    for (int i = 1; i < N; ++i) {
        ll dx = A[i] - A[i-1];
        dmg += min(dx, g);
        if (dmg >= H) return true;
    }
    return false;
}

ll solve() {
    cin >> N >> H; A.resize(N);
    for (ll &x : A) cin >> x;
    // A.push_back(LLONG_MAX);  // dummy value

    ll lo = 1, hi = H;
    while (lo < hi) {
        ll mid = lo + (hi-lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";
}
