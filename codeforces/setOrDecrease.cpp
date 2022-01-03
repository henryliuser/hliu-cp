// https://codeforces.com/blog/entry/98453
// nice question. nested binary search on g,x
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()

vector<ll> A;
ll n, k, sum;

ll score(ll g, ll x) {
    ll res = sum - x;
    ll y = A[0] - x;
    for (int i = 0; i < min(g-x, n-1); ++i)
        res -= (A[n-i-1] - y);
    return -res;
}

bool check(ll g) {
    ll lo = 0, hi = g;
    while (lo < hi) {  // find peak on score g
        ll mid = lo + (hi-lo) / 2;
        ll a = score(g, mid);
        bool ok = (0 <= mid+1 && mid+1 <= g);
        ll b = (ok) ? score(g,mid+1) : LLONG_MIN;
        if (-a <= k) return true;
        if (a == b) return -a <= k;
        if (a < b) lo = mid+1;
        else hi = mid;
    }
    return -score(g, lo) <= k;
}

ll solve() {
    cin >> n >> k;
    sum = 0;
    A.resize(n);
    for (ll &x : A) {
        cin >> x;
        sum += x;
    }
    if (sum <= k) return 0;

    sort(all(A));
    ll lo = 1, hi = 1e18;
    while (lo < hi) {
        ll mid = lo + (hi-lo) / 2ll;
        if (check(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << "\n";
}
