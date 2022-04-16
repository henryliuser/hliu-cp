// https://codeforces.com/problemset/problem/1601/B
// cool bfs problem actually.
// key observation is to see that you can reduce the # of edges
// only need to travel TO each depth at most once.
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using pi = pair<int, int>;
#define all(x) begin(x), end(x)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> A(N+1), B(N+1), pred(N+1, -1);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1; i <= N; ++i) cin >> B[i];

    set<int> pos;
    for (int x = 0; x < N; ++x)
        pos.insert(-x);

    bitset<300001> seen;
    auto bfs = [&]() {
        int lvl = 0;
        queue<pi> q;
        q.push( {N,N} );
        seen[N] = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [u,p] = q.front();
                q.pop();
                auto it = pos.lower_bound(-u);
                while (it != end(pos) && -(*it) >= u - A[u]) {
                    int v = -(*it);    // before slide
                    if (pred[v] == -1) pred[v] = p;
                    if (v == 0) return lvl+1;
                    int s = v + B[v];  // after slide
                    if (!seen[s]) {
                        q.push( {s,v} );
                        seen[s] = 1;
                    }
                    it = pos.erase(it);
                }
            }
            ++lvl;
        }
        return -1;
    };

    int ans = bfs();
    cout << ans << '\n';
    if (ans == -1) return 0;
    int cur = 0;
    vector<int> path;
    while (cur != N) {
        path.push_back(cur);
        cur = pred[cur];
    }
    reverse( all(path) );
    for (int x : path)
        cout << x << ' ';
}
