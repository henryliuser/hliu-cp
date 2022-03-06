// https://codeforces.com/problemset/problem/1648/A
// sum the distsums for xs and ys
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

struct DistSum {
    vector<ll> d[2], p[2];  // 0 left->right, 1 right->left
    DistSum(vector<ll> &a) {
        int n = a.size();
        for (int i : {0,1}) d[i].assign(n,0), p[i].assign(n,0);
        for (int i = 1; i < n; ++i) {
            d[0][i] = a[i] - a[i-1] + d[0][i-1];    // psum of dists
            p[0][i] = d[0][i] + p[0][i-1];  // psum of psum of dists
            d[1][n-i-1] = a[n-i] - a[n-i-1] + d[1][n-i];
            p[1][n-i-1] = d[1][n-i-1] + p[1][n-i];
        }
    }
    ll query(int src, int i) {
        int q = (src > i);
        ll diff = p[q][i] - p[q][src];
        ll cut = d[q][src];
        ll len = abs(src-i);
        return diff - cut * len;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;
    map<int, vector<ll>> xs, ys;
    for (int i = 0; i < N; ++i)
        for (int c, j=0; j < M; ++j) {
            cin >> c;
            xs[c].push_back(i);
            ys[c].push_back(j);
        }

    ll ans = 0;
    for (int z : {0,1}) {
        for (auto &[c, L] : xs) {
            int sz = L.size();
            sort( all(L) );
            DistSum ds(L);
            for (int i = 0; i < sz; ++i)
                ans += ds.query(i, sz-1);
        }
        swap(xs,ys);
    }
    cout << ans << '\n';

}
