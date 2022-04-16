// https://atcoder.jp/contests/abc246/tasks/abc246_e
// modified dijkstra
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
const int INF = 1e9+5;
using state = array<int, 4>;  // {depth, r, c, [0:SE, 1:NE, 2:NW, 3:SW]}

int dist[1501][1501][5];
int dirs[4][2] = { {1,1}, {1,-1}, {-1,-1}, {-1,1} };

int main() {
    int *p = (int*) dist;
    fill(p, p+1501*1501*5, INF);
    cin.tie(0)->sync_with_stdio(0);

    int N, ax, ay, bx, by;
    cin >> N >> ax >> ay >> bx >> by;
    vector<string> grid(N);
    for (auto &s : grid) cin >> s;

    --ax, --ay, --bx, --by;
    priority_queue<state> pq;
    dist[ax][ay][4] = 0;
    pq.push( {0, ax, ay, 4} );
    while (!pq.empty()) {
        state s = pq.top();
        pq.pop();
        if (-s[0] != dist[s[1]][s[2]][s[3]]) continue;
        for (int i : {0,1,2,3}) {
            int r = s[1] + dirs[i][0];
            int c = s[2] + dirs[i][1];
            if (r < 0 || r >= N || c < 0 || c >= N) continue;
            if (grid[r][c] == '#') continue;
            int nd = -s[0] + (i != s[3]);  // new depth
            if (nd < dist[r][c][i]) {
                dist[r][c][i] = nd;
                pq.push( {-nd,r,c,i} );
            }
        }
    }
    int ans = *min_element(dist[bx][by], dist[bx][by]+4);
    cout << (ans != INF ? ans : -1) << '\n';
}
