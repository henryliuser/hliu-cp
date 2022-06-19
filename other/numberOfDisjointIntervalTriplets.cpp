#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

#define all(x) begin(x), end(x)
using pi = pair<int,int>;

struct BIT {
    int N;
    vector<ll> bit;
    BIT(int n) : N(n), bit(n+1) {}
    void update(int i, ll val) {
        for (++i; i <= N; i = i & -i)
            bit[i] += val;
    }
    ll query(int i, ll res=0) {
        for (++i; i > 0; i ^= i & -i)
            res += bit[i];
        return res;
    }
};

const int MXX = 1e6+5;
// works for K-tuples in O(KN log N)
// for triplets we can just call it N log N
ll disjointIntervals(vector<pi> &A) {
    sort( all(A) );
    int N = A.size();

    ll ans = 0;
    BIT dp1(MXX), dp2(MXX)  // assume all values in [0,1e6]
    // otherwise, coordinate compress or use MergeSortTree
    for (int i = 0; i < N; ++i) {
        auto [L,R] = A[i];
        ll x = dp1.query(L-1);   // assume inclusive bounds
        ans += dp2.query(L-1);   // sum from 0 to L-1
        dp1.update(R, 1);        // dp1[R] += 1
        dp2.update(R, x);        // dp2[R] += x
    }
    return ans;
}

// O(N^3) brute force checker
ll verify(vector<pi> &A) {
    ll ans = 0;
    int N = A.size();
    for (int i = 0; i < N; ++i)
        for (int j = i+1; j < N; ++j)
            for (int k = j+1; k < N; ++k) {
                vector<pi> c = {A[i], A[j], A[k]};
                sort(all(c));
                auto [l1, r1] = c[0];
                auto [l2, r2] = c[1];
                auto [l3, r3] = c[2];
                ans += (l2 > r1 && l3 > r2);
            }
    return ans;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N; cin >> N;
        vector<pi> A(N);
        for (pi &p : A)
            cin >> p.first >> p.second;
        ll a = verify(A);
        ll b = disjointIntervals(A);
        cout << a << '\n' << b;
        if (a != b) printf("\nWRONG ON %d!", t);
        cout << "\n\n";
    }
}

/*
case generator in python:

from random import randint as rng
T = 100
print(T)
for _ in range(T):
    N = rng(20, 400)
    A = []
    for i in range(N):
        x = rng(1, N-3)
        y = rng(x, N)
        A += [ (x,y) ]
    print(N)
    for i in A:
        print(*i)
*/
