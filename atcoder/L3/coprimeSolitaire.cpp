// https://atcoder.jp/contests/abc210/tasks/abc210_f
// pairwise co-prime: for every prime p, there can only
// exist AT MOST ONE (AMO) number with p as a factor.
// using 2-product AMO SAT encoding, courtesy of Jingchao Chen:
// https://www.it.uu.se/research/group/astra/ModRef10/papers/Jingchao%20Chen.%20A%20New%20SAT%20Encoding%20of%20the%20At-Most-One%20Constraint%20-%20ModRef%202010.pdf
// add the corresponding clauses for each prime and check if satisfiable.
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

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

    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
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

int N;
vector<int> C[2];

struct Encoding {
    int z = 0;
    int vars = 0;
    TwoSAT *ts;
    vector<bool> aux;
    explicit Encoding(int n) : aux(2*n) {
        ts = new TwoSAT(3*n);
        for (int i = 0; i < n; ++i)
            take(i);
    }
    void take(int k) {
        if (aux[k]) return;
        aux[k] = true;
        ++vars;
    }
    void add(int i, bool f, int j, bool g) {
        if (N <= i && i < 2*N) f ^= 1, i -= N;
        if (N <= j && j < 2*N) g ^= 1, j -= N;
        ts->add_clause(i,f,j,g);
        take(i), take(j);
    }
    int mex() {
        while (aux[z] && z < aux.size()) ++z;
        take(z);
        return z;
    }
    bool satisfiable() const { return ts->satisfiable(); }
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

const int MXA = 2e6+1;
int spf[MXA] = {};
void sieve(int N) {
    spf[0] = spf[1] = -1;
    for (int i = 3; i <= N; i += 2) spf[i] = i;
    for (int i = 2; i <= N; i += 2) spf[i] = 2;  // avoid lots of % later
    for (int i = 3; i*i <= N; i += 2) {
        if (spf[i] != i) continue;
        for (int j = i*i; j <= N; j += i)
            if (spf[j] == j)
                spf[j] = i;
    }
}

int main() {
    int mxa = 0;
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int j : {0,1}) C[j].resize(N);
    for (int i = 0; i < N; ++i)
        for (int j : {0,1}) {
            cin >> C[j][i];
            mxa = max(mxa, C[j][i]);
        }
    sieve(mxa+1);
    Encoding enc(2*N);
    unordered_map<int, vector<int>> e(N/5);
    for (int j : {0,1}) {
        for (int i = 0; i < N; ++i) {
            int x = C[j][i];
            int last = -5;
            while (x != 1) {
                int p = spf[x];
                if (p != last)              // A[i] : i
                    e[p].push_back(i+j*N);  // B[i] : i+N
                x /= p;
                last = p;
            }
        }
    }
    for (auto &[p,v] : e) AMO(v, enc);
    cout << (enc.satisfiable() ? "Yes" : "No") << '\n';
}
