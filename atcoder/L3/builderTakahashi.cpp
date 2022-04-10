// https://atcoder.jp/contests/abc239/tasks/abc239_g
// interpret as a network flow problem.
// construct a new graph with vertices 1 to N, and 1' to N'.
// only construct outgoing edges from G to G'.
// add_edge(u, v')
// add_edge(v, u')
// the only incoming edges in G are:
//   for all u in [2, N-1]:
//      add_edge(u', u, c[u])
//
// notice that in this new graph,
// you can only reach nodes in G if you pay the cost.
// you can move to any nodes in G' as long as you can reach the nodes in G
// so, it remains to find the minimum cost of edges to cut such that
// it is no longer possible to reach N'.
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const ll INF = 1e18+5;

// begin ACL
namespace internal {
    template <class T> struct queue {
        std::vector<T> payload;
        int pos = 0;
        inline void reserve(int n) { payload.reserve(n); }
        inline int size() const { return int(payload.size()) - pos; }
        inline bool empty() const { return pos == int(payload.size()); }
        inline void push(const T& t) { payload.push_back(t); }
        inline T& front() { return payload[pos]; }
        inline T pop() { return payload[pos++]; }
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

    inline int add_edge(int from, int to, Cap cap) {
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
    inline void change_edge(int i, Cap new_cap, Cap new_flow) {
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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    MaxFlow<ll> mf(2*N+1);
    for (int u,v, i=0; i < M; ++i) {
        cin >> u >> v;
        mf.add_edge(u, v+N, INF);  // u --inf->  v'
        mf.add_edge(v, u+N, INF);  // v --inf->  u'
    }
    for (ll c, i=1; i <= N; ++i) {
        cin >> c;
        if (i==1 || i==N) continue;
        mf.add_edge(i+N, i, c);    // u' --(c_u)->  u
    }

    vector<int> ans;
    cout << mf.flow(1, 2*N) << '\n';
    vector<bool> reach = mf.min_cut(1);
    for (auto e : mf.edges()) {
        if (!e.flow || e.from != e.to+N) continue;
        if (reach[e.from] ^ reach[e.to])  // min cut
            ans.push_back(e.to);
    }
    cout << ans.size() << '\n';
    for (int v : ans)
        cout << v << " ";

}
