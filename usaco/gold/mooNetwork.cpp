#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define tl(x) array<ll, x>
#define all(x) (x).begin(), (x).end()
const ll INF = 1e18;

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

int N;
vector<tl(2)> A, xs[11];
priority_queue<tl(3)> pq;
vector<int> L[11], R[11];

inline ll dist(ll a, ll b, ll c, ll d) {
    ll dx = c-a, dy = d-b;
    return dx*dx + dy*dy;
}
//
// inline tl(3) getNext(int i, int y) {
//     tl(3) res;
//     auto &V = xs[y];
//     int M = V.size();
//     int &j = R[y][i];
//     if (0 <= j && j < M) {
//         ll a = V[j][0];
//         ll d = dist(A[i][0], A[i][1], a, y);
//         ++j;
//         return {-d, i, V[j][1]};
//     }
//     ll
//     ll d1 = INF, d2 = INF;
//     if (a != INF) d1 = dist(A[i][0], A[i][1], a, y);
//     if (b != INF) d2 = dist(A[i][0], A[i][1], b, y);
//     if (d1 < d2) {
//         res = {-d1, i, V[lo][1]};
//         --lo;
//     }
//     else {
//         res = {-d2, i, V[hi][1]};
//         ++hi;
//     }
//     return res;
// }

// inline void get() {
//     for (int y = 0; y <= 10; ++y)
//         for (int i = 0; i < N; ++i)
//             try { pq.push( getNext(i,y) ); }
//             catch(...) {}
// }

// inline void init() {
//     for (int y = 0; y <= 10; ++y) {
//         auto &V = xs[y];
//         sort(all(V));
//         R[y].resize(N);
//         for (int i = 0; i < N; ++i) {
//             tl(2) qry = {A[i][0], i};
//             int k = lower_bound(all(V), qry) - begin(V);
//             R[y][i] = k;
//             if (k == V.size()) continue;
//             auto &p = V[k];
//             if (p == qry) R[y][i]++;
//         }
//     }
// }

inline ll solve() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        auto &p = A[i];
        cin >> p[0] >> p[1];
    }
    sort(all(A));
    for (int i = 0; i < N; ++i)
        xs[ A[i][1] ].push_back( {A[i][0],i} );

    vector<tl(3)> db;
    for (int i = 0; i < N; ++i)
        for (int j = i+1; j < N; ++j) {
            ll d = dist(A[i][0], A[i][1], A[j][0], A[j][1]);
            db.push_back({d,i,j});
        }
    sort(all(db));
    DSU uf(N);
    ll ans = 0;
    for (int i = 0; i < db.size(); ++i) {
        auto p = db[i];
        if (uf.unite(p[1], p[2]))
            ans += p[0],
            cout << p[1] << " " << p[2] << " " << p[0] << "\n";
        if (uf.count == 1) return ans;
    }

    // init();
    // DSU uf(N);
    // ll ans = 0;
    // while (1) {
    //     get();
    //     while (!pq.empty()) {
    //         auto p = pq.top();
    //         pq.pop();
    //         if (p[1] == p[2]) continue;
    //         if (uf.unite(p[1], p[2]))
    //             ans -= p[0];
    //         if (uf.count == 1) return ans;
    //     }
    // }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << solve() << '\n';
}
