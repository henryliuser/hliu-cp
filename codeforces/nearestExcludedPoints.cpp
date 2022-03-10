// https://codeforces.com/contest/1651/problem/D
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using pi = array<int, 2>;
const int mx = 2e5+5;
const int inf = 1e9+5;
const int lim = 1e6;

map<int, int> xs[mx];
vector<pi> A;
pi dp[mx];
int dirs[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

ll mdist(pi &a, pi &b) {
    return abs(a[0] - b[0]) + abs(b[1] - a[1]);
}

pi dfs(int i) {
    pi &res = dp[i];
    if (res[0] != -inf) return res;
    pi &p = A[i];
    int x = p[0], y = p[1];
    vector<int> pts;
    res = {-1,-1};  // currently looking for answer
    for (auto &d : dirs) {
        int r = x + d[0];
        int c = y + d[1];
        if (!xs[c].count(r)) {
            if (r <= lim && c <= lim && r >= -lim && c >= -lim)
                return res = {r,c};
        }

        int j = xs[c][r];
        if (dp[j][0] == -inf)
            pts.push_back(j);
    }
    ll d = 1e9+5;
    for (int j : pts) {
        auto q = dfs(j);
        ll m = mdist(p, q);
        if (m < d) {
            d = m;
            res = q;
        }
    }
    return res;
}

int main() {
    for (int i = 0; i < mx; ++i)
        dp[i] = {-inf,-inf};
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y;
        A[i] = {x,y};
        xs[y][x] = i;
    }

    for (int i = 0; i < N; ++i) {
        auto x = dfs(i);
        cout << x[0] << " " << x[1] << '\n';
    }
}
