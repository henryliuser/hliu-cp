// https://leetcode.com/problems/minimum-interval-to-include-each-query/
// 3 methods detailed in this file.

// 1. my favorite method:
// sort intervals by size and consume the queries greedily
// ~600 ms with unordered_map and 1100ms with map
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using pi = array<int,2>;
const int INF = 1e9+5;
#define all(x) begin(x), end(x)
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& ivals, vector<int>& qry) {
        int Q = qry.size();
        int N = ivals.size();
        set<int> qs( all(qry) );
        sort( all(ivals), [](const auto &a, const auto &b) {
            return (a[1]-a[0]) < (b[1]-b[0]);
        });

        unordered_map<int, int> res(Q);
        for (auto &p : ivals) {
            int L = p[0];
            int R = p[1];
            int sz = R-L+1;
            auto it = qs.lower_bound(L);
            while (it != end(qs) && *it <= R) {
                res[*it] = sz;
                it = qs.erase(it);
            }
        }
        vector<int> ans(Q, -1);
        for (int q = 0; q < Q; ++q) {
            int x = qry[q];
            if (res.count(x))
                ans[q] = res[x];
        }

        return ans;
    }
};

// ========================================================================

// slight variation on 1
// just track the occurrences of each q and fill them out
using pi = pair<int,int>;
const int INF = 1e9+5;
#define all(x) begin(x), end(x)
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& ivals, vector<int>& qry) {
        int Q = qry.size();
        int N = ivals.size();

        map<int, vector<int>> qs;
        for (int i = 0; i < Q; ++i)
            qs[ qry[i] ].push_back(i);  // log occurrences of each q

        sort( all(ivals), [](const auto &a, const auto &b) {
            return (a[1]-a[0]) < (b[1]-b[0]);  // sort by ascending size
        });

        vector<int> ans(Q, -1);
        for (auto &p : ivals) {
            int L = p[0], R = p[1];
            int sz = R - L + 1;
            auto it = qs.lower_bound(L);
            while (it != end(qs) && it->first <= R) {
                for (int i : it->second)  // answer all occurrences
                    ans[i] = sz;
                it = qs.erase(it);
            }
        }
        return ans;
    }
};


// ========================================================================


// 2. sweep line
// seems to be the fastest though, consistently 600ms
// apparently there's heap solution whatever
using ll = long long;
using pi = pair<int,int>;
const int F = 1e7+5;
#define all(x) begin(x), end(x)
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& ivals, vector<int>& qry) {
        vector<pi> e;
        int Q = qry.size();
        int N = ivals.size();
        for (auto &iv : ivals) {
            int sz = iv[1]-iv[0]+1;
            e.emplace_back( iv[0], sz );
            e.emplace_back( iv[1]+1, -sz );   // -sz indicate end
        }
        for (int i = 0; i < Q; ++i)
            e.emplace_back( qry[i], i+F+1 );  // > F indicate query

        // at a single point i, events will be processed in order:
        // 1. REMOVALS,  2. ADDITIONS,  3. QUERIES

        sort( all(e) );
        map<int, int> cur;
        vector<int> ans(Q, -1);
        for (auto [i,x] : e) {
            if (x > F) {  // query
                if (!cur.empty())
                    ans[ x-F-1 ] = cur.begin()->first;
            }
            else {
                int sz = abs(x);
                int m = (x < 0) ? -1 : 1;
                if ( (cur[sz]+=m) <= 0 )  // toggle an interval
                    cur.erase(sz);
            }
        }
        return ans;
    }
};
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();


// ========================================================================


// 3. mergeSortTree with suffix min at each node
// slow, but can answer queries online
// runtime varies 1300ms - 1900ms. consistently AC though.
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using ll = long long;
using pi = array<int,2>;
const int INF = 1e9+5;
#define all(x) begin(x), end(x)

struct MergeTree {
    int N;
    vector<vector<pi>> T;
    vector<vector<int>> &P;
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            auto &x = P[tl];  // taking this out is more readable
            T[v] = { {x[1], x[1]-x[0]+1} };  // and seemingly faster
        }
        else {
            int mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            auto &V = T[v];    // wonder if this is more performant?
            V.resize(tr-tl+1);
            auto &L = T[v*2], &R = T[v*2+1];
            merge( all(L), all(R), begin(V) );
            for (int i = tr-tl-1; ~i; --i)
                V[i][1] = min(V[i][1], V[i+1][1]);
        }
    }
    inline int query(int x, int L, int R) { return query(x, L, R, 1, 0, N-1); }
    inline int query(int x, int al, int ar, int v, int tl, int tr) {
        if (tr < al || ar < tl) return INF;
        if (al <= tl && tr <= ar) {
            pi tmp = {x,-1};
            auto it = lower_bound( all(T[v]), tmp );
            if (it == end(T[v])) return INF;
            return (*it)[1];
        }
        int mid = (tl + tr) / 2;
        int ql = query(x, al, ar, v*2, tl, mid);
        int qr = query(x, al, ar, v*2+1, mid+1, tr);
        return min(ql, qr);
    }
    MergeTree(int n, vector<vector<int>> &p)
        : N(n), P(p), T(4ul*n) { build(1, 0, N-1); }
};

struct Solution {
    vector<int> minInterval(vector<vector<int>>& ivals, vector<int>& qry) {
        sort( all(ivals) );
        int Q = qry.size();
        int N = ivals.size();

        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            A[i] = ivals[i][0];

        vector<int> ans(Q, -1);
        MergeTree seg(N, ivals);
        for (int i = 0; i < Q; ++i) {
            int x = qry[i];
            int j = upper_bound( all(A), x ) - begin(A);
            if (j == 0) continue;
            int res = seg.query(x, 0, j-1);
            ans[i] = (res==INF) ? -1 : res;
        }
        return ans;
    }
};
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
