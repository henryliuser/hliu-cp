#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pcl = array<int, 4>;
#define umap unordered_map

int N;
vector<string> grid;
vector<pcl> maybe;
int dirs[4][2] = {{1,0}, {0,1}, {0,-1}, {-1,0}};

pcl lims;
void dfs(int r, int c, char ch, vector<vector<bool>> &seen) {
    seen[r][c] = true;
    for (auto d : dirs) {
        int x = r + d[0];
        int y = c + d[1];
        if (x < lims[0] || x > lims[2]) continue;
        if (y < lims[1] || y > lims[3]) continue;
        if (grid[x][y] != ch) continue;
        if (seen[x][y]) continue;
        dfs(x, y, ch, seen);
    }
}

umap<char, int> comps(int r1, int c1, int r2, int c2) {
    umap<char, int> cnt;
    vector<vector<bool>> seen(N, vector<bool>(N));
    for (int i = r1; i <= r2; ++i)
        for (int j = c1; j <= c2; ++j)
            if (!seen[i][j]) {
                char ch = grid[i][j];
                lims = {r1,c1,r2,c2};
                dfs(i, j, ch, seen);
                ++cnt[ch];
            }
    return cnt;
}

string check(umap<char, int> &cnt) {
    if (cnt.size() < 2) return "nope";
    if (cnt.size() > 2) return "skip";
    auto it = begin(cnt);
    auto a = *it;
    auto b = *next(it);
    if (a.second == 1 && b.second >  1) return "okay";
    if (a.second  > 1 && b.second == 1) return "okay";
    return "nope";
}

bool contained(pcl &a, pcl &b) {
    if (a[0] < b[0]) return false;
    if (a[1] < b[1]) return false;
    if (a[2] > b[2]) return false;
    if (a[3] > b[3]) return false;
    return true;
}

void init() {
     freopen("where.in", "r", stdin);
     freopen("where.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N; grid.resize(N);
    for (auto &s : grid)
        cin >> s;
}

int main() {
    init();
    for (int r1 = 0; r1 < N; ++r1)
        for (int c1 = 0; c1 < N; ++c1)
            for (int r2 = r1; r2 < N; ++r2)
                for (int c2 = c1; c2 < N; ++c2) {
                    umap<char,int> cnt = comps(r1,c1,r2,c2);
                    string sig = check(cnt);
                    if (sig == "skip") break;
                    if (sig == "okay")
                        maybe.push_back({r1,c1,r2,c2});
                }

    int C = maybe.size();
    vector<bool> ok(C, 1);
    for (int i = 0; i < C; ++i) {
        pcl &a = maybe[i];
        for (int j = i+1; j < C; ++j) {
            pcl &b = maybe[j];
            if (contained(a, b)) {
                ok[i] = false;
                break;
            }
            if (contained(b, a))
                ok[j] = false;
        }
    }

    int ans = 0;
    for (int i = 0; i < C; ++i)
        if (ok[i]) ++ans;
    cout << ans << "\n";
}
