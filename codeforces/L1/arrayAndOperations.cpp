#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    int N, K; cin >> N >> K;
    vector<ll> A(N);
    for (ll &x : A) cin >> x;

    ll ans = 0;
    sort(begin(A), end(A));
    for (int i = N-2*K; i < N-K; ++i)
        ans += A[i] / A[i+K];
    for (int i = 0; i < N-2*K; ++i)
        ans += A[i];
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
