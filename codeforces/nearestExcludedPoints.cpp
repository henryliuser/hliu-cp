// https://codeforces.com/contest/1651/problem/D
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using pi = pair<int,int>;
const int MXN = 2e5+5;

#define X first
#define Y second

map<int, int> pts[MXN];
int dirs[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

void solve() {
    int N; cin >> N;
    vector<pi> A(N);
    for (int x,y, i=0; i < N; ++i) {
        cin >> x >> y;
        pts[x][y] = i;
        A[i] = {x,y};
    }

    queue<int> q;
    vector<pi> ans(N, {-5,-5});
    for (int i = 0; i < N; ++i) {
        auto &p = A[i];
        for (auto &d : dirs) {
            int r = p.X + d[0];
            int c = p.Y + d[1];
            if (!pts[r].count(c)) {
                ans[i] = {r,c};
                q.push(i);
                break;
            }
        }
    }

    while (!q.empty()) {
        int i = q.front();
        auto &p = A[i];
        for (auto &d : dirs) {
            int r = p.X + d[0];
            int c = p.Y + d[1];
            if (!pts[r].count(c)) continue;
            int j = pts[r][c];
            if (ans[j].X != -5) continue;  // seen
            ans[j] = ans[i];
            q.push(j);
        }
        q.pop();
    }

    for (auto [x,y] : ans)
        cout << x << " " << y << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    solve();
}
