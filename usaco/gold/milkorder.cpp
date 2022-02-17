// http://www.usaco.org/index.php?page=viewproblem2&cpid=838
// binary search over X, pq top sort bfs to check
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

int N, M;
vector<int> indeg;
vector<vector<int>> obs, adj;

vector<int> bfs() {
    vector<int> res;
    vector<int> ideg = indeg;
    priority_queue<int> pq;
    for (int c = 1; c <= N; ++c)
        if (indeg[c] == 0)
            pq.push(-c);

    while (!pq.empty()) {
        int u = -pq.top();
        res.push_back(u);
        pq.pop();
        for (int v : adj[u]) {
            if (--ideg[v] != 0) continue;
            pq.push(-v);
        }
    }
    if (res.size() == N) return res;
    return {};
}

vector<int> check(int X) {
    adj.clear();
    adj.resize(N+1);
    indeg.assign(N+1, 0);
    for (int i = 0; i < X; ++i) {
        int prev = 0;
        vector<int> &o = obs[i];
        for (int c : o) {
            if (prev) {
                adj[prev].push_back(c);
                ++indeg[c];
            }
            prev = c;
        }
    }
    return bfs();
}

int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int mi; cin >> mi;
        vector<int> o(mi);
        for (int &x : o) cin >> x;
        obs.push_back(o);
    }
    vector<int> ans(N);
    iota(all(ans), 1);
    int lo = 0, hi = M;
    while (lo < hi) {
        int mid = lo + (hi-lo+1)/2;
        auto s = check(mid);
        if (s.empty()) hi = mid-1;
        else lo = mid, ans = s;
    }

    for (int i = 0; i < N-1; ++i)
        cout << ans[i] << ' ';
    cout << ans[N-1] << '\n';
}
