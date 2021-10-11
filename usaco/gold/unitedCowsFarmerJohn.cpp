#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct MergeSortTree {
    unsigned long N;
    vector<vector<int>> T;  // tree representation
    vector<int> &A;  // array reference
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
    int query(int al, int ar) { return query(al, ar, ar, 1, 0, N-1); }
    int query(int al, int ar, int R, int v, int tl, int tr) {
        if (al > ar) return 0;
        if (al == tl && ar == tr)
            return end(T[v]) - upper_bound(begin(T[v]), end(T[v]), R);
        int mid = (tl + tr) / 2;
        int ql = query(al, min(ar, mid), R, v*2, tl, mid);
        int qr = query(max(al, mid+1), ar, R, v*2+1, mid+1, tr);
        return ql + qr;
    }
    MergeSortTree(unsigned long n, vector<int>& a)
        : N{n}, A{a}, T{4*n, vector<int>()} { build(1,0,N-1); }
};

int main() {
    ll ans = 0;
    unsigned long N; cin >> N;
    vector<int> cows(N);
    for (int i = 0; i < N; ++i)
        cin >> cows[i];
    unordered_map<int, int> next;
    vector<int> neq(N);
    for (int i = N-1; i >= 0; --i) {
        int x = cows[i];
        neq[i] = INT_MAX;
        if (next.count(x))
            neq[i] = next[x];
        next[x] = i;
    }
    MergeSortTree seg{N, neq};

    for (int i = 0; i < N; ++i) {
        int x = cows[i];
        int j = min(neq[i]-1, (int)N-1);
        ans += seg.query(i+1, j);
    }
    cout << ans << endl;

}
