


// with a merge tree, TLE on cses
//
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
//
// struct MergeTree {
//     int N;
//     vector<int> &A;
//     vector<vector<int>> T;
//     void build(int v, int tl, int tr) {
//         if (tl == tr) T[v] = {A[tl]};
//         else {
//             int mid = (tl + tr) / 2;
//             build(v*2, tl, mid);
//             build(v*2+1, mid+1, tr);
//             T[v].resize(tr-tl+1);
//             auto &L = T[v*2], &R = T[v*2+1];
//             merge(begin(L), end(L), begin(R), end(R), begin(T[v]));
//         }
//     }
//     int query(int x, int L, int R) { return query(x, L, R, 1, 0, N-1); }
//     int query(int x, int al, int ar, int v, int tl, int tr) {
//         if (al > ar) return 0;
//         if (al == tl && ar == tr)
//             return end(T[v]) - upper_bound(begin(T[v]), end(T[v]), x);
//         int mid = (tl + tr) / 2;
//         int ql = query(x, al, min(ar, mid), v*2, tl, mid);
//         int qr = query(x, max(mid+1, al), ar, v*2+1, mid+1, tr);
//         return ql + qr;
//     }
//     MergeTree(int n, vector<int> &v)
//         : N(n), A(v), T(4ul*n) { build(1, 0, N-1); }
// };
//
// int main() {
//     int N, Q; cin >> N >> Q;
//     vector<int> A(N);
//     for (int i = 0; i < N; ++i)
//         cin >> A[i];
//
//     map<int, int> mp;
//     vector<int> nxt(N);
//     for (int i = N-1; i >= 0; --i) {
//         nxt[i] = INT_MAX;
//         if (mp.count(A[i]))
//             nxt[i] = mp[A[i]];
//         mp[A[i]] = i;
//     }
//
//     MergeTree seg(N, nxt);
//     while (Q--) {
//         int L, R; cin >> L >> R;
//         cout << seg.query(R-1, L-1, R-1) << "\n";
//     }
// }
