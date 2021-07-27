#include <bits/stdc++.h>
using namespace std;

int W, H;
int ans = 0;
int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
vector<string> grid;
vector<vector<bool>> seen;
void dfs(int r, int c) {
    if (grid[r][c] == 'G') ans++;
    vector<pair<int, int>> s;
    for (auto& d : dirs) {
        int x = r + d[0];
        int y = c + d[1];
        bool valid = x >= 0 && x < H && y >= 0 && y < W;
        if (!valid || seen[x][y]) continue;
        if (grid[x][y] == 'T')
            return;
        if (grid[x][y] == '.' || grid[x][y] == 'G') {
            seen[x][y] = true;
            s.push_back({x,y});
        }

    }
    for (auto& pt : s) dfs(pt.first, pt.second);
}

int main() {
    int sx, sy;
    cin >> W >> H;
    grid.assign(H, "");
    seen.assign(H, vector<bool>(W));
    for (int r = 0; r < H; ++r) {
        cin >> grid[r];
        for (int c = 0; c < W; ++c)
            if (grid[r][c] == 'P')
                sx = r, sy = c;
    }
    seen[sx][sy] = true;
    dfs(sx, sy);
    printf("%d\n", ans);
}
