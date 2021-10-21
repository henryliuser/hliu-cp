#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

int N;
int needToPlace = 0;
int comf[3000][3000];
bool grid[3000][3000];
int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

void place(int x, int y) {
    if (grid[x][y]) return;
    ++needToPlace;
    grid[x][y] = 1;
    for (auto &d : dirs) {
        int r = x + d[0];
        int c = y + d[1];
        ++comf[r][c];
        if (comf[x][y] == 3)
            place(r, c);
        if (grid[r][c] && comf[r][c] == 3) {
            for (auto &q : dirs) {
                int i = r + q[0];
                int j = c + q[1];
                place(i, j);
            }
        }
    }
}

int main() {
    cin >> N;
    memset(grid, 0, sizeof grid);
    memset(comf, 0, sizeof comf);
    for (int placed = 1; placed <= N; ++placed) {
        int x, y; cin >> x >> y;
        place(x+1000, y+1000);
        cout << needToPlace - placed << endl;
    }

}
