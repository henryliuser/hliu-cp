// Consider the grid-graph: all edges between adjacent squares
// A. the goal is to maximize the # of dichrome adjacencies.
// B. eqvuialently, we can minimize the # of monochrome adjacencies.
//
// what we're capable of: minimizing the # of dichrome adjacencies.
// elaboration: The minimum cut of a flow graph divides the nodes into
// 2 colors, source and sink. It also gives us the minimum number of edges
// that we need to sever in order to split the nodes into the 2 components.
// therefore the min-cut is the minimum # of dichrome adjacencies.
// for a node u with predetermined color, we add edges with INF weight
// from [src (black) to u], or from [u to sink (white)]. This way,
// we ensure that those edges won't be cut and those
// nodes then MUST be a part of their predetermined components.
//
// we want to exploit min-cut to give us the max # of dichrome adjacencies.
// an equivalent goal is minimizing the # of monochrome adjacencies.
// if we flip the grid colors on a checkerboard pattern (if i+j is odd, flip)
// 2 properties are enforced:
//    1. previously monochrome edges become dichrome (and vice versa)
//    2. in the resulting graph, as a consequence of (1),
//       if we MINIMIZE the # of new dichrome edges,
//       we are then minimizing the # of old monochrome edges,
//       satisfying condition B.
//
// there are a total of 2N(N-1) edges. The minCut is equal to the
// minimum # of monochrome edges. The max # of dichrome edges, is therefore:
// total - minCut
//
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const int INF = 1e9+5;

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
        T pop() { return payload[pos++]; }
        void clear() {
            payload.clear();
            pos = 0;
        }
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
                int v = que.pop();
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
                Cap d = self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
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
            int p = que.pop();
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


int dirs[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    vector<string> grid(N);
    for (auto &s : grid) cin >> s;

    int S = N*N;
    int T = S+1;
    MaxFlow<int> mf(N*N+2);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            int u = i*N+j;
            for (auto &d : dirs) {
                int r = i + d[0];
                int c = j + d[1];
                if (r<0||r>=N||c<0||c>=N) continue;
                int v = r*N+c;
                mf.add_edge(u, v, 1);
            }
            char c = grid[i][j];
            if (c == '?') continue;
            bool flip = (i+j) % 2;
            if (flip) c ^= 'B' ^ 'W';  // if odd, flip color
            if (c == 'B') mf.add_edge(S, u, INF);
            if (c == 'W') mf.add_edge(u, T, INF);  // big weights won't be cut
        }

    int minCut = mf.flow(S,T);  // min # of dichrome edges in flipped world
    int total = 2 * N * (N-1);  // 	^^ (also == min # of og monochrome edges)
    cout << total - minCut << '\n';
}
