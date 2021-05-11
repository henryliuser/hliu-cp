#include <bits/stdc++.h>
using namespace std;

int rcol;
int M, N;
int dirs[8][2] = {{1,1}, {1,0}, {1,-1}, {0,1}, {0,-1}, {-1,1}, {-1,0}, {-1,-1}};
void dfs(int r, int c, vector<vector<char>>& grid) {
    if (grid[r][c] == 'X') return;
    if (c > rcol) throw true;
    grid[r][c] = 'X';
    for (auto& d : dirs) {
        int x = r + d[0];
        int y = c + d[1];
        if (x >= 0 && x < M && y >= 0 && y < N) {
            if (grid[x][y] == '-' || grid[x][y] == 'R')
                dfs(x, y, grid);
        }
    }
}

int main() {
    cin >> M >> N;
    vector<vector<char>> grid(M, vector<char>(N));
    int cx, cy;
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            cin >> grid[r][c];
            if (grid[r][c] == 'R') rcol = c;
            if (grid[r][c] == 'C') {cx = r, cy = c;}
        }
    }
    if (rcol == N-1) cout << "no" << endl;
    else {
        try {dfs(cx, cy, grid);}
        catch (bool z) {cout << "yes" << endl; return 0;}
        cout << "no" << endl;
    }
}
