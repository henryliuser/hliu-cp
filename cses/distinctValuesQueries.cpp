// need unordered_map::reserve && fastIO to get AC
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static constexpr int MXN = 2e5+1;
int nxt[MXN];
struct MergeTree {
    int N;
    vector<vector<int>> T;
    void build(int v, int tl, int tr) {
        if (tl == tr) T[v] = {nxt[tl]};
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
        if (al > ar) return 0;
        if (al == tl && ar == tr)
            return end(T[v]) - upper_bound(begin(T[v]), end(T[v]), x);
        int mid = (tl + tr) / 2;
        int ql = query(x, al, min(ar, mid), v*2, tl, mid);
        int qr = query(x, max(mid+1, al), ar, v*2+1, mid+1, tr);
        return ql + qr;
    }
    MergeTree(int n)
        : N(n), T(4ul*n) { build(1, 0, N-1); }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    unordered_map<int, int> mp;
    mp.reserve(MXN);
    for (int i = N-1; i >= 0; --i) {
        nxt[i] = INT_MAX;
        if (mp.count(A[i]))
            nxt[i] = mp[A[i]];
        mp[A[i]] = i;
    }

    MergeTree seg(N);
    while (Q--) {
        int L, R; cin >> L >> R;
        cout << seg.query(R-1, L-1, R-1) << "\n";
    }
}
