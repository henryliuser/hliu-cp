#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int N;
    vector<int> &A, T, lazy;
    void build(int v, int tl, int tr) {
        if (tl == tr) T[v] = A[tl];
        else {
            int mid = (tl + tr) / 2;
            build(v*2, tl, mid);
            build(v*2+1, mid+1, tr);
            T[v] = T[v*2] + T[v*2+1];
        }
    }
    void update(int dx, int L, int R) { update(dx,L,R,1,0,N-1); }
    void update(int dx, int al, int ar, int v, int tl, int tr) {
        prop(v, tl, tr);
        if (tr < al || ar < tl) return;
        if (al <= tl && tr <= ar) lazy[v] += dx;
        else {
            int mid = (tl + tr) / 2;
            update(dx, al, ar, v*2, tl, mid);
            update(dx, al, ar, v*2+1, mid+1, tr);
            prop(v*2, tl, mid);
            prop(v*2+1, mid+1, tr);
            T[v] = T[v*2] + T[v*2+1];
        }
    }
    int query(int L, int R) { return query(L,R,1,0,N-1); }
    int query(int al, int ar, int v, int tl, int tr) {
        prop(v, tl, tr);
        if (tr < al || ar < tl) return 0;
        if (al <= tl && tr <= ar)
            return T[v];
        int mid = (tl + tr) / 2;
        int ql = query(al, ar, v*2, tl, mid);
        int qr = query(al, ar, v*2+1, mid+1, tr);
        return ql + qr;
    }
    void prop(int v, int tl, int tr) {
        T[v] += (tr - tl + 1) * lazy[v];
        if (tl > tr) return;
        lazy[v*2] += lazy[v];
        lazy[v*2+1] += lazy[v];
        lazy[v] = 0;
    }

    SegTree(int n, vector<int> &a)
        : N(n), A(a), T(4*n), lazy(4*n) { build(1,0,n-1); }
};

int main() {
    vector<int> v = {0,1,2,3,4,5,6,7};
    SegTree seg(8, v);
    for (int i = 0; i < 8; ++i)
        cout << seg.query(i, i) << " "; cout << "\n";
    cout << seg.query(3, 5) << "\n";
    cout << seg.query(0, 3) << "\n";
    cout << seg.query(0, 4) << "\n";
    seg.update(2, 0, 3);
    for (int i = 0; i < 8; ++i)
        cout << seg.query(i, i) << " "; cout << endl;
    cout << seg.query(0, 3) << "\n";
    cout << seg.query(0, 4) << "\n";
    seg.update(1, 0, 2);
    for (int i = 0; i < 8; ++i)
        cout << seg.query(i, i) << " "; cout << endl;
    cout << seg.query(0, 3) << "\n";
}
