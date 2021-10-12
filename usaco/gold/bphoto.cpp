#include <bits/stdc++.h>
using namespace std;

struct MergeTree {
    int N;
    vector<int> &A;  // array reference
    vector<vector<int>> T;  // tree representation
    void build(int v, int tl, int tr) {
        if (tl == tr) T[v] = {A[tl]};
        else {
            int mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            T[v].resize(tr-tl+1);
            auto &l = T[v*2], &r = T[v*2+1];
            merge(begin(l), end(l), begin(r), end(r), begin(T[v]));
        }
    }
    int query(int x, int al, int ar) { return query(x, al, ar, 1, 0, N-1); }
    int query(int x, int al, int ar, int v, int tl, int tr) {
        if (al > ar) return 0;
        if (al == tl && ar == tr)
            return end(T[v]) - upper_bound(begin(T[v]), end(T[v]), x);
        int mid = (tl + tr) / 2;
        int ql = query(x, al, min(ar, mid), v*2, tl, mid);
        int qr = query(x, max(al, mid+1), ar, v*2+1, mid+1, tr);
        return ql + qr;
    }
    MergeTree(int n, vector<int>& a)
        : N{n}, A{a}, T{4ul*n, vector<int>()} { build(1,0,N-1); }
};

int main() {
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    int ans = 0;
    int N; cin >> N;
    vector<int> height(N);
    for (int i = 0; i < N; ++i)
        cin >> height[i];
    MergeTree seg{N, height};
    for (int i = 0; i < N; ++i) {
        int Li = seg.query(height[i], 0, i-1);
        int Ri = seg.query(height[i], i+1, N-1);
        int mx = max(Li, Ri);
        int mn = min(Li, Ri);
        if (mx > 2*mn) ++ans;
    }

    printf("%d\n", ans);
}
