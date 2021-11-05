// O(nk) dp
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    int N, K; cin >> N >> K;
    vector<int> A(N), dp(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    int mx = 0;
    for (int i = 0; i < min(N,K); ++i) {
        mx = max(mx, A[i]);
        dp[i] = mx * (i+1);
    }
    for (int i = K; i < N; ++i) {
        mx = 0;
        for (int j = 1; j <= K; ++j) {
            mx = max(mx, A[i-j+1]);
            dp[i] = max(dp[i], dp[i-j] + mx * j);
        }
    }
    cout << dp[N-1] << endl;
}



// atrocious RMQ dp lmfao
// #include <bits/stdc++.h>
// using namespace std;
//
// struct SegTree {
//     int N;
//     vector<int> &A, T;
//     void build(int v, int tl, int tr) {
//         if (tl == tr) T[v] = A[tl];
//         else {
//             int mid = (tl + tr) / 2;
//             build(v*2, tl, mid);
//             build(v*2+1, mid+1, tr);
//             T[v] = max(T[v*2], T[v*2+1]);
//         }
//     }
//     int query(int L, int R) { return query(L, R, 1, 0, N-1); }
//     int query(int al, int ar, int v, int tl, int tr) {
//         if (al > ar) return 0;
//         if (al == tl && ar == tr) return T[v];
//         int mid = (tl + tr) / 2;
//         int ql = query(al, min(ar, mid), v*2, tl, mid);
//         int qr = query(max(mid+1, al), ar, v*2+1, mid+1, tr);
//         return max(ql, qr);
//     }
//     SegTree(int n, vector<int> &a)
//         : N(n), A(a), T(4*n) { build(1, 0, n-1); }
// };
//
// int main() {
//     freopen("teamwork.in", "r", stdin);
//     freopen("teamwork.out", "w", stdout);
//     int N, K; cin >> N >> K;
//     vector<int> A(N);
//     for (int i = 0; i < N; ++i)
//         cin >> A[i];
//     SegTree rmq(N, A);
//     vector<int> dp(N);
//     int mx = 0;
//     for (int i = 0; i < min(N,K); ++i) {
//         mx = max(mx, A[i]);
//         dp[i] = mx * (i+1);
//     }
//     for (int i = K; i < N; ++i) {
//         dp[i] = dp[i-1] + A[i];
//         for (int j = 2; j <= K; ++j) {
//             mx = rmq.query(i-j+1, i);
//             dp[i] = max(dp[i], dp[i-j] + mx*j);
//         }
//     }
//     cout << dp[N-1] << endl;
//
// }
