#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, X; cin >> N >> X;
    vector<ll> A(N);
    for (ll &x : A) cin >> x;
    sort(begin(A), end(A));
    map<ll, vector<int>> idx;
    for (int i = 0; i < N; ++i)
        idx[A[i]].push_back(i);

    ll ans = 0;
    vector<bool> seen(N);
    for (int i = 0; i < N; ++i) {
        if (seen[i]) continue;
        seen[i] = 1;
        ll v = A[i];
        ll t = v * X;
        auto &q = idx[t];
        if (q.empty()) ++ans;
        else {
            int j = q.back();
            q.pop_back();
            seen[j] = 1;
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
