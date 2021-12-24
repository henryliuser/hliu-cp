// https://codeforces.com/contest/1579/problem/E2
// just greedy seems to work. 
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
    int query(int x, int Y, int L, int R) { return query(x, Y, L, R, 1, 0, N-1); }
    int query(int x, int Y, int al, int ar, int v, int tl, int tr) {
        if (tr < al || ar < tl) return 0;
        if (al <= tl && tr <= ar) {
            if (Y == 0) return end(T[v]) - upper_bound(begin(T[v]), end(T[v]), x);
            if (Y == 1) return lower_bound(begin(T[v]), end(T[v]), x) - begin(T[v]);
        }
        int mid = (tl + tr) / 2;
        int ql = query(x, Y, al, ar, v*2, tl, mid);
        int qr = query(x, Y, al, ar, v*2+1, mid+1, tr);
        return ql + qr;
    }
    MergeTree(int n, vector<int> &v)
        : N(n), A(v), T(4ul*n) { build(1, 0, N-1); }
};

ll solve() {
    ll ans = 0;
    int N; cin >> N;
    vector<int> A(N);
    for (int &x : A) cin >> x;
    MergeTree seg(N, A);
    for (int i = 1; i < N; ++i) {
        int x = A[i];
        int a = seg.query(x, 0, 0, i-1);
        int b = seg.query(x, 1, 0, i-1);
        ans += min(a, b);
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << "\n";
}
