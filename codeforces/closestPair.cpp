// https://codeforces.com/problemset/problem/1635/F
// solve the question for whole array in O(N) first
// monostack:
// W: 100  99   1
// x:  1  100  99
// i:  0   1    2
//
// no need to consider pair (0,2) because (1,2) clearly better
// thus, define L, R such that
// L[i] = max j such that j<i && w[j] <= w[i]
// R[i] = min j such that j>i && w[j] <= w[i]
// now we taken the min across 2N points (L[i], i), (i, R[i])
//
// for range query, we take the minimum pair that's fully contained in [l, r]
// for all l,r there is guaranteed to be some pair that is fully contained.
//
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pl = array<ll, 2>;

template<class vec, class f>
void mono(vec &idx, vec &m, vec &W, f p) {
    stack<ll> s;
    for (ll i : idx) {
        ll j = s.top();
        while (!s.empty() && p(W[j], m[i])) {
            m[j] = i;
            s.pop();
            j = s.top();
        }
        s.push(i);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> L(N,-1), R(N,-1);
    vector<ll> X(N), W(N), ans(Q);
    map<int, vector<pl>> occ;
    for (int i = 0; i < N; ++i)
        cin >> X[i] >> W[i];
    for (int i = 0; i < Q; ++i) {
        int l, r; cin >> l >> r;
        occ[r].push_back( {l,i} );
    }
    for (auto &[r,v] : occ)
        sort( all(v) );

    vector<ll> nxt(N), prv(N);
    iota(nxt, nxt+N, 0), iota(prv, prv+N, 0);
    reverse(prv, prv+N);
    auto lt = [](ll a, ll b) { return a < b; }
    auto gt = [](ll a, ll b) { return a > b; }
    mono(nxt, R, W, gt), mono(prv, L, W, lt);

    






}
