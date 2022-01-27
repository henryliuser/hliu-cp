// https://codeforces.com/group/KIrM1Owd8u/contest/365107/problem/D
// sub-rect sum is just sum(A[i..j]) * sum(B[i..j])
// find the min sub-array sum for each dimension
// try all dimensions and pick the best valid
// 1 2 4 3
// 2 2 8 2

//  2  2  8  2
//  4  4 16  4
//  8  8 32  8
//  6  6 18  6
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<ll> A(N), B(M);
    for (ll &x : A) cin >> x;
    for (ll &x : B) cin >> x;
    ll X; cin >> X;

    vector<ll> C(N+1, INF), D(M+1, INF);  // they'll swap
    for (int K : {M,N}) {
        for (int sz = 1; sz <= K; ++sz) {
            ll cur = 0;
            for (int i = 0; i < sz; ++i)
                cur += B[i];
            D[sz] = min(D[sz], cur);
            for (int i = sz; i < K; ++i) {
                cur = cur - B[i-sz] + B[i];
                D[sz] = min(D[sz], cur);
            }
        }
        swap(A, B);
        swap(C, D);
    }

    int ans = 0;
    for (int h = 1; h <= N; ++h)
        for (int w = 1; w <= M; ++w)
            if (C[h] * D[w] <= X)
                ans = max(ans, h*w);

    cout << ans << '\n';
}
