#include <bits/stdc++.h>
using namespace std;
using pt = array<int, 2>;
using ll = long long;

int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

void solve() {
    int N, M; cin >> N >> M;
    vector<string> grid(N), ans;
    vector<vector<bool>> seen(N, vector<bool>(M));
    for (auto &s : grid) cin >> s;

    pt lab;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (grid[i][j] == 'L')
                lab = {i,j};

    ans = grid;
    ans[lab[0]][lab[1]] = '+';
    queue<pt> q;

    q.push(lab);
    while(!q.empty()) {
        int sz = q.size();
        // while (sz--) {
        //     // maybe try everything here, push into vector
        //     // then dfs/bfs from all new +'s
        // }
        pt p = q.front(); q.pop();
        int r = p[0], c = p[1];
        seen[r][c] = true;
        vector<pt> reach, adj;
        for (auto &d : dirs) {
            int x = r + d[0];
            int y = c + d[1];
            if (x < 0 || x >= N) continue;
            if (y < 0 || y >= M) continue;
            if (grid[x][y] == '#') continue;
            reach.push_back({x,y});
            if (r == lab[0] && c == lab[1])
                q.push({x,y});
            //     q.push({x,y});
            //     seen[x][y] = true;
            // }
        }
        int cnt = 0;
        for (pt &f : reach)
            cnt += (ans[f[0]][f[1]] == '+');
        if (cnt >= reach.size() - 1) {
            ans[r][c] = '+';
            for (pt &f : reach)
                if (!seen[f[0]][f[1]]) {
                    seen[f[0]][f[1]] = true;
                    q.push(f);
                }

        }

    }

    ans[lab[0]][lab[1]] = 'L';
    for (auto &s : ans)
        cout << s << "\n";

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--)  solve();
}

/*
1
3 2
.#
..
L.
*/
