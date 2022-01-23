#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct MergeTree {
    int N;
    vector<int> &A;
    vector<vector<int>> T;
    void build(int v, int tl, int tr) {
        if (tl == tr) T[v] = {A[tl]};
        else {
            int mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            T[v].resize(tr-tl+1);
            auto &L = T[v*2], &R = T[v*2+1];
            merge(begin(L), end(L), begin(R), end(R), begin(T[v]));
        }
    }
    int query(int x, int L, int R) { return query(x, L, R, 1, 0, N-1); }
    int query(int x, int al, int ar, int v, int tl, int tr) {
        if (tr < al || ar < tl) return 0;
        if (al <= tl && tr <= ar) {
            auto R = upper_bound(begin(T[v]), end(T[v]), x);
            auto L = lower_bound(begin(T[v]), end(T[v]), x);
            return R-L;
        }
        int mid = (tl + tr) / 2;
        int ql = query(x, al, ar, v*2, tl, mid);
        int qr = query(x, al, ar, v*2+1, mid+1, tr);
        return ql + qr;
    }
    MergeTree(int n, vector<int> &v)
        : N(n), A(v), T(4ul*n) { build(1, 0, N-1); }
};

vector<int> solve() {
    int N; cin >> N;
    vector<int> A(N), B;
    for (int &x : A) cin >> x;

    int mex = 0;
    set<int> cur;
    MergeTree seg(N, A);
    for (int i = 0; i < N; ++i) {
        int x = A[i];
        cur.insert(x);
        if (x == mex) {
            while (cur.count(mex)) ++mex;
        }
        int c = seg.query(mex, i+1, N-1);
        if (c == 0) {
            B.push_back(mex);
            cur.clear();
            mex = 0;
        }
    }
    return B;
}

int main() {
    int t; cin >> t;
    while (t--) {
        auto s = solve();
        cout << s.size() << '\n';
        for (int x : s) cout << x << " ";
        cout << '\n';
    }
}
