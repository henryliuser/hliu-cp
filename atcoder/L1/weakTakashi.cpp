#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int M, N, ans = 0;
bool seen[101][101];
vector<string> grid;
int dirs[4][2] = {{0,1}, {1,0}};

void dfs(int i, int j) {
    seen[i][j] = 1;
    ans = max(ans, i+j+1);
    for (auto &d : dirs) {
        int r = i + d[0];
        int c = j + d[1];
        if (r < 0 || r >= M || c < 0 || c >= N) continue;
        if (seen[r][c]) continue;
        if (grid[r][c] == '#') continue;
        dfs(r, c);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    memset(seen, 0, sizeof seen);
    cin >> M >> N; grid.resize(M);
    for (auto &s : grid) cin >> s;
    if (grid[0][0] != '#')
        dfs(0,0);
    cout << ans << "\n";
}
