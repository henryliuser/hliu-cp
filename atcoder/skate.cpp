// https://atcoder.jp/contests/abc241/tasks/abc241_f
// probably the easiest 1900-rated / ABC-F on atcoder
// japanese coders are so strong at math but why so few solved this bfs?
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using pi = array<int, 2>;
#define all(x) begin(x), end(x)

template <class Map>
inline pi lower(Map &mp, int a, int b, bool flip) {
    auto it = lower_bound(all(mp[a]), b);
    if (it == begin(mp[a])) return {-1,-1};
    int x = a, y = *(--it)+1;
    if (flip) return {y, x};
    return {x, y};
}
template <class Map>
inline pi upper(Map &mp, int a, int b, bool flip) {
    auto it = upper_bound(all(mp[a]), b);
    if (it == end(mp[a])) return {-1,-1};
    int x = a, y = *it - 1;
    if (flip) return {y, x};
    return {x, y};
}

ll solve() {
    pi s, g;
    int N, W, H;
    cin >> H >> W >> N;
    cin >> s[0] >> s[1] >> g[0] >> g[1];

    map<int, vector<int>> xs, ys;
    for (int x,y, i=0; i < N; ++i) {
        cin >> x >> y;
        xs[y].push_back(x);
        ys[x].push_back(y);
    }
    for (auto &[y,L] : xs) sort( all(L) );
    for (auto &[x,L] : ys) sort( all(L) );

    int lvl = 0;
    queue<pi> q;
    q.push(s);
    set<pi> vis = {s};
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [x,y] = q.front();
            q.pop();

            auto  left = lower(xs, y, x, 1);
            auto right = upper(xs, y, x, 1);
            auto    up = upper(ys, x, y, 0);
            auto  down = lower(ys, x, y, 0);

            for (pi d : {left, right, up, down}) {
                if (d[0] < 0 && d[1] < 0) continue;  // none; fall off cliff
                if (vis.count(d)) continue;          // seen before
                if (d == g) return lvl+1;            // found answer
                vis.insert(d);                       // mark trail
                q.push(d);
            }
        }
        ++lvl;
    }
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << solve() << '\n';
}
