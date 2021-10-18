#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

int m, n; 
char grid[1000][1000];
bool seen[1000][1000];
int dirs[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
vector<vector<pii>> pred;

int bfs(pii st, pii end) {
    queue<pii> q;
    q.push(st);
    int layer = 0;
    pred[st.f][st.s] = {-1, -1};
    seen[st.f][st.s] = 1;
    while (!q.empty()) {
        ++layer;
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            pii &p = q.front();
            q.pop();
            for (auto d : dirs) {
                int x = p.f + d[0];
                int y = p.s + d[1];
                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                if (grid[x][y] == '#') continue;
                if (seen[x][y]) continue;
                pred[x][y] = {p.f, p.s};
                seen[x][y] = 1;
                if (x == end.f && y == end.s)
                    return layer;
                q.push({x, y});
            }
        }
    }
    return -1;
}

int main() {
    pii st, end;
    cin >> m >> n;
    pred.assign(m, vector<pii>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                st = {i, j};
            if (grid[i][j] == 'B')
                end = {i, j};
        }

    int b = bfs(st, end);
    if (b == -1) {
        printf("NO\n");
        return 0;
    }
    string ans;
    vector<pii> path = {end};
    pii done = {-1, -1};
    while (pred[end.f][end.s] != done) {
        path.push_back(pred[end.f][end.s]);
        end = pred[end.f][end.s];
    }
    for (int i = path.size()-2; i >= 0; --i) {
        char ch = 'w';
        pii p = path[i];
        if (p.f > st.f) ch = 'D';
        if (p.f < st.f) ch = 'U';
        if (p.s > st.s) ch = 'R';
        if (p.s < st.s) ch = 'L';
        ans.push_back(ch);
        st = p;
    }
    printf("YES\n");
    printf("%d\n", b);
    cout << ans << endl;
}
