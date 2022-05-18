// https://codeforces.com/contest/1438/problem/C
// textbook 2-sat
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

struct TwoSAT {
    // BEGIN INTERNAL
    struct scc_graph {
        template <class E> struct csr {
            std::vector<int> start;
            std::vector<E> elist;
            explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
                    : start(n + 1), elist(edges.size()) {
                for (auto e : edges)
                    start[e.first + 1]++;
                for (int i = 1; i <= n; i++)
                    start[i] += start[i - 1];
                auto counter = start;
                for (auto e : edges)
                    elist[counter[e.first]++] = e.second;
            }
        };
        int _n;
        struct edge { int to; };
        std::vector<std::pair<int, edge>> edges;
        explicit scc_graph(int n) : _n(n) {}
        int num_vertices() { return _n; }
        void add_edge(int from, int to) { edges.push_back({from, {to}}); }
        std::pair<int, std::vector<int>> scc_ids() {
            auto g = csr<edge>(_n, edges);
            int now_ord = 0, group_num = 0;
            std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
            visited.reserve(_n);
            auto dfs = [&](auto self, int v) -> void {
                low[v] = ord[v] = now_ord++;
                visited.push_back(v);
                for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                    auto to = g.elist[i].to;
                    if (ord[to] == -1) {
                        self(self, to);
                        low[v] = std::min(low[v], low[to]);
                    } else low[v] = std::min(low[v], ord[to]);
                }
                if (low[v] == ord[v]) {
                    while (true) {
                        int u = visited.back();
                        visited.pop_back();
                        ord[u] = _n;
                        ids[u] = group_num;
                        if (u == v) break;
                    }
                    group_num++;
                }
            };
            for (int i = 0; i < _n; i++)
                if (ord[i] == -1) dfs(dfs, i);
            for (auto& x : ids)
                x = group_num - 1 - x;
            return {group_num, ids};
        }
        std::vector<std::vector<int>> scc() {
            auto ids = scc_ids();
            int group_num = ids.first;
            std::vector<int> counts(group_num);
            for (auto x : ids.second) counts[x]++;
            std::vector<std::vector<int>> groups(ids.first);
            for (int i = 0; i < group_num; i++)
                groups[i].reserve(counts[i]);
            for (int i = 0; i < _n; i++)
                groups[ids.second[i]].push_back(i);
            return groups;
        }
    }; // END INTERNAL
    TwoSAT() : _n(0), scc(0) {}
    explicit TwoSAT(int n) : _n(n), _answer(n), scc(2 * n) {}

    inline void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    inline bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return _answer; }
private:
    int _n;
    std::vector<bool> _answer;
    scc_graph scc;
};

int N, M;
inline int idx(int i, int j) {
    return i * (M+1) + j;
}

int A[102][102];
int dirs[2][2] = {{-1,0}, {0,-1}};
void solve() {
    cin >> N >> M;
    TwoSAT ts((N+1)*(M+1));  // X[i,j] true if (i,j) incremented
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            int &x = A[i][j];
            cin >> x;
            int a = idx(i,j);
            for (auto &d : dirs) {
                int r = i + d[0];
                int c = j + d[1];
                int y = A[r][c];
                int b = idx(r,c);
                if (x == y) {
                    // x xor y
                    ts.add_clause(a,1,b,1);
                    ts.add_clause(a,0,b,0);
                }
                else if (x+1 == y) {
                    ts.add_clause(a,0,b,1);
                }
                else if (y+1 == x) {
                    ts.add_clause(b,0,a,1);
                }
            }
        }
    ts.satisfiable();
    auto ans = ts.answer();
    for (int k = 0; k < (N+1)*(M+1); ++k) {
        int i = k / (M+1);
        int j = k % (M+1);
        A[i][j] += ans[k];
    }
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j)
            cout << A[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    memset(A, -1, sizeof A);
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}
