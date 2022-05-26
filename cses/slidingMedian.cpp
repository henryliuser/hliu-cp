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

template <class T>
struct Compress {
    int sz;
    vector<T> uq;
    Compress(vector<T> &A) { add(A); go(); }
    void add(vector<T> &A) {
        uq.reserve( uq.size() + A.size() );
        uq.insert( end(uq), all(A) );
    }
    int go() {
        sort( all(uq) );
        auto fin = unique( all(uq) );
        uq.resize( fin-begin(uq) );
        return sz = uq.size();
    }
    inline  T  operator[](int i) { return uq[i]; }
    inline int operator()(int x) {
        return lower_bound( all(uq), x ) - begin(uq);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int &x : A) cin >> x;
    Compress<int> cc(A);
    int c = cc.sz;

    BIT ft(c+1);
    auto median = [&]() {
        int l = 0, r = c;
        while (l < r) {
            int m = (l+r) >> 1;
            int x = ft.query(m);
            if (x >= (K+1)/2) r = m;
            else l = m+1;
        }
        return cc[l];
    };

    for (int i = 0; i < K; ++i) {
        int x = A[i];
        ft.update( cc(x), 1 );
    }
    cout << median() << ' ';
    for (int i = K; i < N; ++i) {
        int x = cc( A[i-K] );
        int y = cc(  A[i]  );
        ft.update(x, -1);
        ft.update(y,  1);
        cout << median() << ' ';
    }

}
