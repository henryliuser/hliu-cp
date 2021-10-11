#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int N;
    vector<int> T, &A;  // tree array, array reference
    void build() { build(1, 0, N-1); }
    void build(int v, int tl, int tr) {
        // v: tree index, tl/tr: tree bounds
        if (tl == tr) T[v] = A[tl];
        else {
            int mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            T[v] = T[v*2] + T[v*2+1];  // adjust this
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
        return ql + qr;  // adjust this
    }
    void update(int i, int val) { update(i, val, 1, 0, N-1); }
    void update(int i, int val, int v, int tl, int tr) {
        // i: arr index, val: new value
        if (tl == tr) T[v] = val;
        else {
            int mid = (tl + tr) / 2;
            if (i <= mid) update(i, val, v*2, tl, mid);
            else update(i, val, v*2+1, mid+1, tr);
            T[v] = T[v*2] + T[v*2+1];  // adjust this
        }

    }
    SegTree(int n, vector<int>& a)
        : N{n}, A{a}, T{4*n} {  build(); }
};

int main() {
    // int n = 10;
    // vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    // SegTree seg{n, nums};
    // seg.update(5, 100);
    // cout << seg.query(3, 9) << endl;

    int n = 2;
    vector<int> nums = {9, -8};
    SegTree seg2{n, nums};
    seg2.update(0,3);
    cout << seg2.query(1,1) << seg2.query(0,1) << endl;
    seg2.update(1,-3);
    cout << seg2.query(0,1);


}
