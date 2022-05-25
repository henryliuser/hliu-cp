// https://cses.fi/problemset/task/1076
// binary search a BIT
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
#define all(x) begin(x), end(x)

struct BIT {
    int N;
    vector<int> bit;
    explicit BIT(int n) : N(n), bit(n+1) {}
    void update(int i, int val) {
        for (++i; i <= N; i += i & -i)
            bit[i] += val;
    }
    int query(int i) {
        int res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
};

void compress(vector<int> &A, vector<int> &uq) {
    uq = A;
    sort( all(uq) );
    auto fin = unique( all(uq) );
    uq.resize( fin-begin(uq) );
    return uq;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    vector<int> A(N), uq;
    for (int &x : A) cin >> x;
    compress(A, uq);
    int c = uq.size();

    BIT ft(c+1);
    auto get = [&](int x) {
        return lower_bound( all(uq), x ) - begin(uq);
    };
    auto median = [&]() {
        int l = 0, r = c;
        while (l < r) {
            int m = (l+r) >> 1;
            int x = ft.query(m);
            if (x >= (K+1)/2) r = m;
            else l = m+1;
        }
        return uq[l];
    };

    for (int i = 0; i < K; ++i) {
        int x = get( A[i] );
        ft.update(x, 1);
    }
    cout << median() << '\n';
    for (int i = K; i < N; ++i) {
        int x = get( A[i-K] );
        int y = get(  A[i]  );
        ft.update(x, -1);
        ft.update(y, 1);
        cout << median() << '\n';
    }

}
