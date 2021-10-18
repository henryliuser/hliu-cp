#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<string> grid;
vector<vector<bool>> seen;
int dirs[4][2] = {{1,0}, {0,1}, {0,-1}, {-1,0}};

void dfs(int i, int j) {
    seen[i][j] = 1;
    for (auto d : dirs) {
        int r = i + d[0];
        int c = j + d[1];
        if (r < 0 || r >= m || c < 0 || c >= n)
            continue;
        if (!seen[r][c] && grid[r][c] == '.')
            dfs(r, c);
    }
}

int main() {
    int ans = 0;
    cin >> m >> n;
    grid.resize(m);
    seen.assign(m, vector<bool>(n));
    for (int i = 0; i < m; ++i)
        cin >> grid[i];

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (!seen[i][j] && grid[i][j] == '.') {
                ++ans;
                dfs(i, j);
            }

    cout << ans << endl;



}
