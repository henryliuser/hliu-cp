// https://codeforces.com/problemset/problem/1574/C
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll sum = 0;
vector<ll> A;

ll solve(ll d, ll a) {
    ll send, keep;
    auto it = lower_bound(begin(A), end(A), d);
    if (it == end(A) || it == begin(A)) {
        if (it == end(A)) it = prev(it);
        send = *it, keep = sum - *it;
        return max(d-send, 0ll) + max(a-keep, 0ll);
    }
    ll o = *prev(it);
    send = o, keep = sum - o;
    ll L = max(d-send, 0ll) + max(a-keep, 0ll);
    send = *it, keep = sum - *it;
    ll R = max(d-send, 0ll) + max(a-keep, 0ll);
    return min(L, R);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    cin >> M;
    vector<ll> atk(M), def(M);
    for (int i = 0; i < M; ++i) cin >> def[i] >> atk[i];

    sort(begin(A), end(A));
    for (int i = 0; i < N; ++i)
        sum += A[i];

    for (int q = 0; q < M; ++q) {
        ll d = def[q], a = atk[q];
        cout << solve(d,a) << "\n";
    }

}
