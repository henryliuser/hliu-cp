// https://www.codechef.com/LTIME95A/problems/HKRMAN
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

struct two_sat {
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
    two_sat() : _n(0), scc(0) {}
    explicit two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

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

struct TwoSAT {
    int z = 0;
    int vars = 0;
    two_sat *ts;
    vector<bool> aux;
    explicit Encoding(int n) : aux(3*n) {
        ts = new two_sat(3*n);
        for (int i = 0; i < n; ++i)
            take(i);
    }
    inline void take(int k) {
        if (aux[k]) return;
        aux[k] = true;
        ++vars;
    }
    inline void add(int i, bool f, int j, bool g) {
        ts->add_clause(i,f,j,g);
        take(i), take(j);
    }
    inline int mex() {
        while (aux[z] && z < aux.size()) ++z;
        take(z);
        return z;
    }
    inline bool satisfiable() const { return ts->satisfiable(); }
    ~Encoding() { delete ts; }
};

// recursive 2-product At Most One encoding by Jingchao Chen
// 2n + 4*sqrt(N) + O(N^(1/4))  clauses
// 2*sqrt(N) + O(N^(1/4))       auxiliary variables
void AMO(vector<int> &x, Encoding &enc) {
    int N = x.size();
    if (N <= 3) {
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                enc.add(x[i], false, x[j], false);
        return;
    }
    int p = ceil( sqrt(N) );
    int q = ceil( N*1.0/p );
    vector<int> u(p), v(q);
    for (int i = 0; i < p; ++i) u[i] = enc.mex();  // reserve new auxiliary variables
    for (int i = 0; i < q; ++i) v[i] = enc.mex();
    for (int i = 1; i <= p; ++i)
        for (int j = 1; j <= q; ++j) {
            int k = (i-1) * q + j - 1;
            if (k >= N) break;
            enc.add(x[k], false, u[i-1], true);
            enc.add(x[k], false, v[j-1], true);
        }
    AMO(u, enc);
    AMO(v, enc);
}

#define all(x)  begin(x), end(x)
#define  ti(x)  array<int, x>

int N, D, K;
map<int, vector<ti(2)>> xs, ys;

// divide & conquer
void dnc(int l, int r, vector<ti(2)> &v, TwoSAT &ts) {
    if (r-l < 1) return;
    int m = (r+l) >> 1;
    dnc(l,m), dnc(m+1,r);
    if (v[r][0] - D <= v[l][0] + D) {
        vector<int> x;
        for (int i = l; i <= r; ++i)
            x.push_back(v[i][1]);
        AMO(x, enc);
    }
}

void solve() {
    cin >> N >> D >> K;
    for (int x,y, i=0; i < K; ++i) {
        cin >> x >> y;
        xs[y].push_back( {x,i} );
        ys[x].push_back( {y,i} );
    }
    TwoSAT ts(K);
    for (auto &mp : {xs, ys})
        for (auto &[q,v] : mp) {
            sort( all(v) );
            dnc(0, v.size()-1, v, ts);
        }
    bool ok = ts.satisfiable();
    cout << (ok ? "Yes" : "No") << '\n';
    if (!ok) return;
    auto ans = ts.ts.answer();
    for (bool b : ans) cout << b << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}
