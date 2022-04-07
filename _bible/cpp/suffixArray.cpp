#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
#define f first
#define s second

struct SuffixArray {
    int N; string &S;
    vector<int> P, C, lcp;
    inline short cmp(int i, string &q) {
        for (int j = 0; j < q.size(); ++j) {
            if (S[j+i] < q[j]) return 0;
            if (S[j+i] > q[j]) return 2;
        }
        return 1;
    }
    inline int bisect(string &q, int gt) {
        int l = 1, r = N;
        while (l < r) {
            int m = (l+r)/2;
            if (cmp(P[m], q) > gt) r = m;
            else l = m+1;
        }
        return l;
    }
    template<typename A, typename K>
    inline void countSort(A &P, K &C) {
        int N = P.size();
        vector<int> res(N), cnt(N), pos(N);
        for(int x : C) ++cnt[x];
        for(int i = 1; i < N; ++i)
            pos[i] = pos[i-1] + cnt[i-1];
        for(int x : P) res[pos[C[x]]++] = x;
        swap(P, res);
    }
    template<typename FN>
    inline void assign(FN& g) {
        vector<int> res(N);
        for (int i = 1; i < N; ++i) {
            int diff = ( g(i) != g(i-1) );
            res[P[i]] = res[P[i-1]] + diff;
        }
        swap(C, res);
    }
    SuffixArray(string &s) : N(s.size()+1), S(s), P(N), C(N) {
        S += "$";
        vector<pi> A(N);
        for (int i = 0; i < N; ++i) A[i] = {S[i], i};
        sort(begin(A), end(A));
        for (int i = 0; i < N; ++i) P[i] = A[i].s;
        auto g = [&](int i) { return A[i].f; };
        assign(g);
        for (int k = 0; (1<<k) < N; ++k) {
            for (int i = 0; i < N; ++i)
                P[i] = (P[i] - (1<<k) + N) % N;
            countSort(P, C);
            auto h = [&](int i) {
                pi p = {C[P[i]], C[(P[i] + (1<<k)) % N]};
                return p;
            };
            assign(h);
        }
    }
    void buildLCP() {
        int k = 0;
        lcp.assign(N, 0);
        for (int i = 0; i < N-1; ++i) {
            int j = P[C[i]-1];
            while (S[i+k] == S[j+k]) ++k;
            lcp[C[i]] = k;
            k = max(k-1, 0);
        }
    }
};

int main() {
    string s; cin >> s;
    SuffixArray sfx(s);
    sfx.buildLCP();

    for (int i : sfx.P) cout << i << " "; cout << "\n";
    for (int i = 1; i < sfx.N; ++i)
        cout << sfx.lcp[i] << " ";
}
