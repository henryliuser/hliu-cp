// WIP
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

struct BIT {
    int N;
    vector<ll> bit;
    BIT(int n) : N(n), bit(n+1) {}
    BIT(vector<ll> &a) : BIT(a.size()) {
        for (int i = 0; i < N; ++i)
            update(i, a[i]);
    }
    void update(int i, ll val) {
        for (++i; i <= N; i += i & -i)
            bit[i] += val;
    }
    ll query(int i) {
        ll res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
};


int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;
    string S; cin >> S;

    S = "x" + S;
    vector<int> A(N+1);
    for (int i = 1; i <= N; ++i)
        A[i] = (A[i] == A[i-1]);

    BIT ft(A);
    for (int l,r, i=0; i < Q; ++i) {
        cin >> l >> r;
        cout << ft.query(l-1, r) << '\n';
    }
}
