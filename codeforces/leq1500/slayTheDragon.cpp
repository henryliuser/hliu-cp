// https://codeforces.com/problemset/problem/1574/C
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll sum = 0;
vector<ll> A;

ll solve(ll d, ll a) {
    auto it = lower_bound(begin(A), end(A), d);
    if (it == end(A)) it = prev(it);
    ll send = *it, keep = sum-send;
    ll L = max(0ll, d-send) + max(0ll, a-keep);
    if (it == begin(A)) return L;
    send = *prev(it), keep = sum-send;
    ll R = max(0ll, d-send) + max(0ll, a-keep);
    return min(L, R);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N; A.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    sort(begin(A), end(A));
    for (int i = 0; i < N; ++i)
        sum += A[i];

    cin >> M;
    for (int q = 0; q < M; ++q) {
        ll d, a; cin >> d >> a;
        cout << solve(d,a) << "\n";
    }

}
