#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

int N, cl, rl, cb, rb;
static constexpr int MAXN = 1e5+1;
bool grid[MAXN][MAXN];

int bfs() {
    int ans = -1;
    int layer = 0;
    queue<pii> q;
    q.push({})
}

int main() {
    // freopen("lasers.in", "r", stdin);
    // freopen("lasers.out", "w", stdout);
    cin >> N >> cl >> rl >> cb >> rb;
    vector<pii> fences(N+2) = {{cl, rl}, {cb, rb}};
    vector<int> xs(N), ys(N);
    for (int i = 2; i < N+2; ++i)
        cin >> fences[i].s >> fences[i].f;

    // coordinate compression
    sort(begin(fences), end(fences));
    for (int i = 1; i < N; ++i) {
        auto [y,x] = fences[i];
        if (y == rb && x == cb)
        int ly = fences[i-1].f;
        if (cy == rb && fences[i].s
    }
    // TODO: sort indices based on fence instead, then 0 and 1 are laser, barn
        ys[i] = (fences[i].f > fences[i-1].f) + ys[i-1];
    sort(begin(fences), end(fences),
        [&](auto &a, auto &b) { return a.s < b.s; });
    for (int i = 1; i < N; ++i)
        xs[i] = (fences[i].s > fences[i-1].s) + xs[i-1];
    for (int i = 0; i < N; ++i)
        grid[ys[i]][xs[i]] = 1;




}
