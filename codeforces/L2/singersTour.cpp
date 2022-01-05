// https://codeforces.com/contest/1618/problem/E
// nice math question. write it all out, look for patterns
// just start subtracting stuff.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> solve() {
    ll N; cin >> N;
    vector<ll> B(N), A(N);

    ll s = 0;  // sum of B
    for (ll &x : B) {
        cin >> x;
        s += x;
    }
    if (N == 1) return {B[0]};
    ll k = N * (N+1) / 2;
    if (s % k != 0) return {};
    s /= k;  // now s = sum(A)

    for (int i = 0; i < N; ++i) {
        int j = (i-1+N) % N;  // circular prev
        // B[i] - B[j] = s - N*A[i]
        ll dx = B[i] - B[j];
        if ((s-dx) % N != 0) return {};  // must be int
        A[i] = (s - dx) / N;
        if (A[i] <= 0) return {};
    }
    return A;
}

int main() {
    int t; cin >> t;
    while (t--) {
        auto s = solve();
        if (s.empty()) cout << "NO\n";
        else {
            cout << "YES\n";
            for (ll x : s) cout << x << " ";
            cout << "\n";
        }
    }
}
