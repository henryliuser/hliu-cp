// https://cses.fi/problemset/task/2169/
// coordinate compress, fenwick tree, sweepline
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using pi = array<int, 3>;
#define all(x) begin(x), end(x)

struct BIT {
    int N;
    vector<int> bit;
    BIT(int n) : N(n), bit(n+1) {}
    void clear() { bit.assign(N+1, 0); }
    void update(int i, int val) {
        for (++i; i <= N; i += i & -i)
            bit[i] += val;
    }
    int query(int L, int R) { return query(R) - query(L-1); }
    int query(int i) {
        int res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
};

// in-place coordinate compression
int compress(vector<pi> &A) {
    vector<int> uq;
    for (auto [x,y,i] : A)
        for (int v : {x-1,x,y-1,y})
            uq.push_back(v);
    sort( all(uq) );
    auto fin = unique( all(uq) );
    uq.resize( fin-begin(uq) );
    for (auto &[x,y,i] : A) {
        x = lower_bound( all(uq), x ) - begin(uq);
        y = lower_bound( all(uq), y ) - begin(uq);
    }
    return uq.size();
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    vector<pi> P(N);
    vector<int> uq;
    for (int x,y, i=0; i < N; ++i) {
        cin >> x >> y;
        P[i] = {x, y, i};
    }
    int c = compress(P);

    BIT ft(c+1);
    sort(all(P), [](const pi &a, const pi &b) {
        if (a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    });  // ascending R, descending L
    vector<int> A(N), B(N);   // answers
    for (auto [l,r,i] : P) {
        A[i] = ft.query(l, r);
        ft.update(l, 1);
    }

    ft.clear();
    sort(all(P), [](const pi &a, const pi &b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });  // ascending L, descending R
    for (auto [l,r,i] : P) {
        B[i] = ft.query(r, c);
        ft.update(r, 1);
    }

    for (auto &v : {A,B}) {
        for (int x : v) cout << x << ' ';
        cout << '\n';
    }
}
