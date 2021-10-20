#include <bits/stdc++.h>
using namespace std;
using fence = tuple<int, int, int>;
using pii = pair<int, int>;
#define f first
#define s second

int N, xl, yl, xb, yb;
int dirs[2][4][2] = { {{1,0},{-1,0}}, {{0,1}, {0,-1}} };
static constexpr int MAXN = 1e5+1;
bool grid[MAXN][MAXN];

int bfs(int sx, int sy) {
    int ans = -1;
    int layer = 0;
    vector<vector<bool>> seen[2];
    for (int i : {0, 1})
        seen[i].assign(sx, vector<bool>(sy));

    queue<pair<int, pii>> q;
    q.push({ 0, {xl, yl} });
    q.push({ 1, {xl, yl} });
    while (!q.empty()) {
        ++layer;
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            auto [dir, u] = q.front();
            q.pop();
            for (auto d : dirs[dir]) {
                int x = u.f + d[0];
                int y = u.s + d[1];
                if (x < 0 || x >= sx || y < 0 || y >= sy)
                    continue;
                if (x == xb && y == yb) return layer;
                if (seen[dir][x][y]) continue;
                seen[dir][x][y] = 1;
                q.push({ !dir, {x, y} });
            }
        }
    }
    return -1;
}

int main() {
    // freopen("lasers.in", "r", stdin);
    // freopen("lasers.out", "w", stdout);
    cin >> N >> xl >> yl >> xb >> yb;
    vector<int> xs(N+2), ys(N+2);
    vector<fence> fences(N+2);
    fences.push_back({xl, yl, 0});
    fences.push_back({xb, yb, 1});
    for (int i = 2; i < N+2; ++i) {
        int x, y; cin >> x >> y;
        fences[i] = {x, y, i};
    }

    // coordinate compression
    int sx = 0;
    sort(begin(fences), end(fences));
    for (int i = 0; i < N+2; ++i) {
        auto [x, y, j] = fences[i];
        int nx = (i > 0) ? (x > get<0>(fences[i-1])) : 0;
        xs[j] = sx += nx;
    }
    sort(begin(fences), end(fences),
        [&](auto &a, auto &b) { return get<1>(a) < get<1>(b); });
    int sy = 0;
    for (int i = 0; i < N+2; ++i) {
        auto [x, y, j] = fences[i];
        int ny = (i > 0) ? (y > get<1>(fences[i-1])) : 0;
        ys[j] = sy += ny;
        if (j == 0) xl = xs[j], yl = ys[j];
        if (j == 1) xb = xs[j], yb = ys[j];
    }
    for (int i = 0; i < N+2; ++i)
        grid[ys[i]][xs[i]] = 1;

    cout << bfs(sx+1, sy+1) << endl;
}
