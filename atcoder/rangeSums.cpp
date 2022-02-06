// https://atcoder.jp/contests/abc238/editorial/3370
// interpret as graph. each pair is edge (L-1, R)
// i.e. (2, 2) connects pre[1] to pre[2] because you add the info of A[2]
// check if pre[0] connected to pre[N]
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#define ti(x) array<int, x>

struct DSU {
    int count;
    vector<int> psz;
    DSU(int n) : count(n), psz(n, -1) {}
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (psz[a] > psz[b]) swap(a, b);
        psz[a] += psz[b];
        psz[b] = a;
        --count;
        return true;
    }
    int find(int a) {
        if (psz[a] < 0) return a;
        return psz[a] = find(psz[a]);
    }
};

int main() {
    int N, Q; cin >> N >> Q;
    DSU uf(N+1);
    for (int i = 0; i < Q; ++i) {
        int a, b; cin >> a >> b;
        uf.unite(a-1, b);
    }
    if (uf.find(0) == uf.find(N)) cout << "Yes\n";
    else cout << "No\n";
}

// ignore this
// string solve() {
//     set<ti(2)> seen;
//     int N, Q; cin >> N >> Q;
//     vector<ti(2)> A;
//     for (int i = 0; i < Q; ++i) {
//         int a, b; cin >> a >> b;
//         if (a == 1 && b == N)
//         ti(2) t = {a,b};
//         if (seen.count(t)) continue;
//         seen.insert(t);
//         A.push_back(t);
//     }
//
//     vector<ti(3)> ivals;
//     sort(begin(A), end(A));
//     A.push_back({INF,INF});
//     int imin = A[0][0], neqs = 1, imax = A[0][1];
//     for (int i = 1; i < A.size(); ++i) {
//         int L = A[i][0];
//         int R = A[i][1];
//         if (L > imax) {
//             ivals.push_back({imin, neqs, imax});
//             imin = L, neqs = 1, imax = R;
//         }
//         else {
//             imax = max(imax, R);
//             ++neqs;
//         }
//     }
//     vector<int> cover(N+2);
//     for (auto &iv : ivals) {
//         int L = iv[0], R = iv[2];
//         ++cover[L], --cover[R+1];
//         int nvars = R-L+1 + 1;
//         if (iv[1] < nvars)  // neqs < nvars
//             return "No";
//     }
//     int cur = 0;
//     for (int i = 1; i <= N; ++i) {
//         cur += cover[i];
//         if (cur == 0) return "No";
//     }
//     return "Yes";
// }
//
// int main() {
//     cin.tie(0);
//     ios::sync_with_stdio(0);
//     cout << solve() << '\n';
// }
