#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = array<int, 2>;

int N, M, ans = 0;
bool on[101][101], seen[101][101];
unordered_map<string, vector<pi>> graph;
int dirs[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

string hsh(int i, int j) {
    return to_string(i) + " " + to_string(j);
}

vector<pi> &adj(int i, int j) {
    return graph[hsh(i,j)];
}

void bfs() {
    queue<pi> q;  // active
    unordered_set<string> s;  // staged
    q.push({0,0});
    while (!q.empty()) {
        pi p = q.front();
        int r = p[0], c = p[1];
        seen[r][c] = 1;
        for ( pi &z : adj(r,c) ) {
            int x = z[0], y = z[1];
            on[x][y] = 1;
            string h = hsh(x,y);
            if (s.count(h)) {
                s.erase(h);
                if (!seen[x][y])
                    q.push( {x,y} );
            }
        }
        for (auto &d : dirs) {
            int x = p[0] + d[0];
            int y = p[1] + d[1];
            if (x < 0 || x >= N || y < 0 || y >= N) continue;
            if (seen[x][y]) continue;
            if (on[x][y]) q.push( {x,y} );
            else s.insert(hsh(x,y));
        }
        q.pop();
    }
}

int main() {
    memset(on, 0, sizeof on);
    memset(seen, 0, sizeof seen);
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    on[0][0] = 1;
    cin >> N >> M;
    while (M--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        adj(x-1, y-1).push_back( {a-1,b-1} );
    }

    bfs();
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            ans += on[i][j];
    cout << ans << "\n";
}
