// no idea what's wrong :(
// WA on 7-10
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pt = array<ll, 2>;
static constexpr ll MOD = 1e9+7;

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
    for (auto &p : xs) sort(begin(p.second), end(p.second));
    for (auto &p : ys) sort(begin(p.second), end(p.second));
    unordered_map<int, vector<ll>> distX, distY, preX, preY;
    for (auto &p : xs) {
        y = p.first; auto &j = p.second;
        int sz = j.size();
        auto &v = distX[y], &q = preX[y];
        v.resize(sz);  v[0] = 0;
        for (int i = 1; i < sz; ++i) v[i] = j[i] - j[i-1];  // get dists
        for (int i = 1; i < sz; ++i) v[i] += v[i-1];        // psum dists
        q = v;
        for (int i = 1; i < sz; ++i)  // psum of psum of dists
            q[i] = (q[i]+q[i-1]) % MOD;
    }
    for (auto &p : ys) {
        x = p.first; auto &j = p.second;
        int sz = j.size();
        auto &v = distY[x], &q = preY[x];
        v.resize(sz);  v[0] = 0;
        for (int i = 1; i < sz; ++i) v[i] = ys[x][i] - ys[x][i-1];
        for (int i = 1; i < sz; ++i) v[i] += v[i-1];
        q = v;
        for (int i = 1; i < sz; ++i)
            q[i] = (q[i]+q[i-1]) % MOD;
    }

    // compute area sums
    for (pt &p : P) {
        x = p[0], y = p[1];
        auto &hori = xs[y], &px = preX[y], &dx = distX[y];
        auto &vert = ys[x], &py = preY[x], &dy = distY[x];
        int idxX = lower_bound(begin(hori), end(hori), x) - begin(hori);
        int idxY = lower_bound(begin(vert), end(vert), y) - begin(vert);

        ll vlt = py[idxY];
        ll vlen = py.size() - idxY - 1;
        ll vtmp = py.back() - vlt;
        ll vgt = vtmp - (dy[idxY] * vlen) % MOD;
        ll vsum = (vlt + vgt) % MOD;

        ll hlt = px[idxX];
        ll hlen = px.size() - idxX - 1;
        ll htmp = px.back() - hlt;
        ll hgt = htmp - (dx[idxX] * hlen) % MOD;
        ll hsum = (hlt + hgt) % MOD;

        ans = (ans + (vsum*hsum)%MOD ) % MOD;
        // ll sums[4]{};
        // sums[0] = (hgt * vlt) % MOD;
        // sums[1] = (hgt * vgt) % MOD;
        // sums[2] = (hlt * vlt) % MOD;
        // sums[3] = (hlt * vgt) % MOD;
        // for (ll s : sums)
        //     ans = (ans + s) % MOD;
    }

    cout << ans << "\n";
}
