#include <bits/stdc++.h>
using namespace std;
using state = array<int, 6>;  // dir1, r1, c1, dir2, r2, c2
// dir = {0:N, 1:E, 2:S, 3:W}

int N;
vector<string> grid;
bool seen[4][21][21][4][21][21];
bool valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}
state right(state d) {
    int a = (d[0] + 5) % 4;
    int b = (d[3] + 5) % 4;
    return {a, d[1], d[2], b, d[4], d[5]};
 }
state left(state d) {
    int a = (d[0] + 3) % 4;
    int b = (d[3] + 3) % 4;
    return {a, d[1], d[2], b, d[4], d[5]};
 }
state forward (state d) {
    for (int i = 0; i <= 3; i+=3) {
        int &r = d[i+1];
        int &c = d[i+2];
        if (r == 0 && c == N-1) continue;
        if (d[i] == 0) r -= (valid(r-1, c) && grid[r-1][c] != 'H');
        if (d[i] == 1) c += (valid(r, c+1) && grid[r][c+1] != 'H');
        if (d[i] == 2) r += (valid(r+1, c) && grid[r+1][c] != 'H');
        if (d[i] == 3) c -= (valid(r, c-1) && grid[r][c-1] != 'H');
    }
    return d;
}
bool done(state d) {
    bool a = (d[1] == 0 && d[2] == N-1);
    bool b = (d[4] == 0 && d[5] == N-1);
    return a && b;
}

int bfs() {
    int depth = 0;
    queue<state> q;
    q.push({0, N-1, 0, 1, N-1, 0});
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            state d = q.front();
            q.pop();
            if (seen[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]]) continue;
            seen[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]] = 1;
            state L = left(d);
            state R = right(d);
            state F = forward(d);
            if (done(L) || done(R) || done(F)) return depth+1;
            q.push(L); q.push(R); q.push(F);
        }
        ++depth;
    }
    return -1;
}

int main() {
    memset(seen, 0, sizeof seen);
    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);
    cin >> N;
    grid.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> grid[i];
    cout << bfs() << endl;
}
