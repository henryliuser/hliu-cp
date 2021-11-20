// at least i solved it..

#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll check(ll g, ll v, vector<ll> &A, int N) {
    vector<ll> B(N);
    B[0] = g;
    ll c = 1, sum = g;
    ll last = g, mult = 2;
    for (int i = 0; i < 2*N-2; i += 2) {
        ll diff = A[i + 2] - A[i];
        B[c] = last + diff / mult;
        if (B[c] == last) throw -1;
        last = B[c];
        sum += B[c++];
        mult += 2;
        if (sum > v) return sum;
    }
    return sum;
}

string solve() {
    int N; cin >> N;
    vector<ll> A(2*N);
    for (ll &x : A) cin >> x;
    sort(begin(A), end(A));
    unordered_map<ll, int> cnt;
    cnt.reserve(2*N);
    for (ll x : A)
        if (x % 2) return "NO";
        else ++cnt[x];
    for (ll x : A) if (cnt[x] % 2) return "NO";
    if (N == 1) return "YES";
    ll mult = 2;
    for (int i = 0; i < N*2-2; i += 2) {
        ll diff = A[i+2] - A[i];
        if (!diff) return "NO";
        if (diff % mult) return "NO";
        mult += 2;
    }
    ll v = A[0]/2;
    ll lo = 1, hi = v;
    while (lo < hi) {
        ll mid = lo + (hi-lo) / 2;
        try {
            ll c = check(mid, v, A, N);
            if (c >  v) hi = mid;
            if (c == v) return "YES";
            if (c <  v) lo = mid+1;
        }
        catch (int nope) { return "NO"; }
    }
    return "NO";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";
}
