// okay fixed* nice question
// precompute psum of psum of distances to answer dist sum queries in O(1)
// iterate on each point and sum the distances in each direction, multiply

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pt = array<ll, 2>;
static constexpr ll MOD = 1e9+7;

struct DistSum {
    vector<ll> d[2], p[2];  // 0 left->right, 1 right->left
    void init(vector<ll> &a) {
        int n = a.size();
        for (int i : {0,1}) d[i].assign(n,0), p[i].assign(n,0);
        for (int i = 1; i < n; ++i) {
            d[0][i] = a[i] - a[i-1] + d[0][i-1];    // psum of dists
            p[0][i] = (d[0][i] + p[0][i-1]) % MOD;  // psum of psum of dists
            d[1][n-i-1] = a[n-i] - a[n-i-1] + d[1][n-i];
            p[1][n-i-1] = (d[1][n-i-1] + p[1][n-i]) % MOD;
        }
    }
    ll query(int src, int i) {
        int q = (src > i);
        ll diff = p[q][i] - p[q][src];
        ll ogd = d[q][src];
        ll len = abs(src-i);
        return (diff - (ogd * len) % MOD) % MOD;
    }
};

int x, y;
int main() {
    // read input
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    unordered_map<int, vector<ll>> xs, ys;
    ll ans = 0;
    int N; cin >> N;
    vector<pt> P(N);
    for (pt &p : P) {
        cin >> x >> y;
        xs[y].push_back(x);
        ys[x].push_back(y);
        p = {x,y};
    }

    // sort, compute distances, compute prefix sum of distances
    unordered_map<int, DistSum> distX, distY;
    for (auto &p : xs) sort(begin(p.second), end(p.second));
    for (auto &p : ys) sort(begin(p.second), end(p.second));
    for (auto &p : xs) distX[p.first].init(p.second);
    for (auto &p : ys) distY[p.first].init(p.second);

    // compute area sums
    for (pt &p : P) {
        x = p[0], y = p[1];
        int N = xs[y].size();
        int M = ys[x].size();
        int idxX = lower_bound(begin(xs[y]), end(xs[y]), x) - begin(xs[y]);
        int idxY = lower_bound(begin(ys[x]), end(ys[x]), y) - begin(ys[x]);

        ll hlt = distX[y].query(idxX, 0);
        ll hgt = distX[y].query(idxX, N-1);
        ll vlt = distY[x].query(idxY, 0);
        ll vgt = distY[x].query(idxY, M-1);
        ll vsum = (vlt + vgt) % MOD;
        ll hsum = (hlt + hgt) % MOD;
        ans = (ans + (vsum*hsum)%MOD) % MOD;
    }

    cout << ans << "\n";
}
