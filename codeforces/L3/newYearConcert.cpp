// https://codeforces.com/problemset/problem/1632/D
// easy observation: can increase by at most 1 at a time.
// (just make it some huge prime number.)
// Two crucial realizations:
// 1. at most N bad subarrays
//    reason: worst case is N subarrays of length 1, (can't intersect)
// 2. for a fixed i, gcd(i..j) s.t. j >= i can never increase.
// which leads us to 2 pointers approach but need to calculate gcd dynamically
// so use segtree
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    while (b)
        swap(a %= b, b);
    return a;
}

struct SegTree {
    int N;
    vector<int> T, &A;  // tree array, array reference
    void build(int v, int tl, int tr) {
        // v: tree index, tl/tr: tree bounds
        if (tl == tr) T[v] = A[tl];
        else {
            int mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            T[v] = gcd(T[v*2], T[v*2+1]);
        }
    }
    int query(int al, int ar) { return query(al, ar, 1, 0, N-1); }
    int query(int al, int ar, int v, int tl, int tr) {
        // al/ar: arr bounds
        if (al > ar) return 0;
        if (al == tl && ar == tr) return T[v];
        int mid = (tl + tr) / 2;
        int ql = query(al, min(ar, mid), v*2, tl, mid);
        int qr = query(max(al, mid+1), ar, v*2+1, mid+1, tr);
        return gcd(ql, qr);
    }
    SegTree(int n, vector<int>& a)
        : N(n), A(a), T(4*n) { build(1, 0, N-1); }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    vector<int> A(N), ans(N);
    for (int &x : A) cin >> x;

    SegTree seg(N, A);
    int i = 0, g = A[0];
    for (int j = 0; j < N; ++j) {
        g = gcd(g, A[j]);
        while (i < N && g < j-i+1)
            g = seg.query(++i, j);
        if (g == j-i+1) {
            ++ans[j];
            i = j+1;
            g = A[i];
        }
    }
    int cur = 0;  // prefix sum
    for (int i = 0; i < N; ++i)
        ans[i] = cur += ans[i];
    for (int x : ans)
        cout << x << ' ';
}
