// https://atcoder.jp/contests/practice2/tasks/practice2_d
// just run bipartite matching on valid ODD and EVEN tiles
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using pi = array<int, 2>;

// begin ACL
namespace internal {
    template <class T> struct queue {
        std::vector<T> payload;
        int pos = 0;
        void reserve(int n) { payload.reserve(n); }
        int size() const { return int(payload.size()) - pos; }
        bool empty() const { return pos == int(payload.size()); }
        void push(const T& t) { payload.push_back(t); }
        T& front() { return payload[pos]; }
        void clear() {
            payload.clear();
            pos = 0;
        }
        void pop() { pos++; }
    };
}
template <class Cap> struct MaxFlow {
public:
    MaxFlow() : _n(0) {}
    explicit MaxFlow(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        std::vector<int> level(_n), iter(_n);
        internal::queue<int> que;

        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                        self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) return res;
            }
            level[v] = _n;
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        internal::queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};
// end ACL

int N, M;
int dirs[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

inline pi coords(int u)      {  return {u/M, u%M};  }
inline int idx(int i, int j) {  return i * M + j;   }

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    vector<string> grid(N);
    for (auto &s : grid) cin >> s;

    int  SRC = N*M;
    int SINK = N*M+1;
    MaxFlow<int> mf(N*M+2);
    // SRC -> odd -> even -> SINK
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == '#') continue;
            bool p = (i+j) % 2;
            int u = idx(i, j);
            if (p) mf.add_edge(SRC, u, 1);
            else   mf.add_edge(u, SINK, 1);
        }
    // odd -> even
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            bool p = (i+j) % 2;
            if (!p || grid[i][j] == '#') continue;
            int u = idx(i, j);
            for (auto &d : dirs) {
                int r = i + d[0];
                int c = j + d[1];
                if (r < 0 || r >= N || c < 0 || c >= M) continue;
                if (grid[r][c] == '#') continue;
                int v = idx(r, c);
                mf.add_edge(u, v, 1);
            }
        }

    cout << mf.flow(SRC, SINK) << '\n';
    for (auto e : mf.edges()) {
        if (!e.flow) continue;
        if (e.from == SRC || e.to == SINK) continue;
        auto [r0, c0] = coords(e.from);
        auto [r1, c1] = coords(e.to);
        if (r0 == r1)
            grid[r0][ min(c0, c1) ] = '>',
            grid[r1][ max(c0, c1) ] = '<';
        if (c0 == c1) // disjoint cases
            grid[ min(r0, r1) ][c0] = 'v',
            grid[ max(r0, r1) ][c1] = '^';
    }

    for (auto &s : grid)
        cout << s << '\n';
}
