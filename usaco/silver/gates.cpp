#include <bits/stdc++.h>
using namespace std;

int lim;
vector<vector<int>> grid;
int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
void dfs(int r, int c, int q) {
    if (grid[r][c] != 0) return;
    grid[r][c] = q;
    for (auto& d : dirs) {
        int x = r + d[0];
        int y = c + d[1];
        if (x >= 0 && x < lim && y >= 0 && y < lim)
            if (grid[x][y] == 0)
                dfs(x, y, q);
    }
}

int main() {
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    int N; cin >> N;
    lim = 2*N+1;
    grid.assign(lim, vector<int>(lim));
    int r = N, c = N;
    for (int z = 0; z < N; z++) {  // awooga brute force line representation LOL
        char ch; cin >> ch;
        int lmao = 2;
        while (lmao--) {
            if (ch == 'N') grid[r--][c] = -1;
            if (ch == 'E') grid[r][c++] = -1;
            if (ch == 'S') grid[r++][c] = -1;
            if (ch == 'W') grid[r][c--] = -1;
        }
    }

    try {  // find the very first 0, (outer region) dfs it to mark
        for (int x = 0; x < lim; x++)
            for (int y = 0; y < lim; y++)
                if (grid[x][y] == 0) {dfs(x, y, -2); throw -1;}
    } catch (...) {}

    int regions = 0;
    for (int x = 0; x < lim; x++) {  // from now on, dfs new regions
        for (int y = 0; y < lim; y++) {
            if (grid[x][y] == -1) {
                if (y+1 < lim && grid[x][y+1] == 0)
                    dfs(x, y+1, ++regions);
                if (x+1 < lim && grid[x+1][y] == 0)
                    dfs(x+1, y, ++regions);
            }
        }
    }
    cout << regions << endl;
}
