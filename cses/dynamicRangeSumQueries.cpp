#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct BIT {
    int N;
    vector<ll> bit, &A;
    BIT(vector<ll> &v) : A(v) {
        N = v.size();
        bit.assign(N+1, 0);
        for (int i = 0; i < N; ++i)
            update(i, A[i], true);
    }
    void update(int i, ll x, bool init=false) {
        ll dx = x;
        if (!init) {
            dx = x - A[i];
            A[i] = x;
        }
        for (++i; i <= N; i += i & -i)
            bit[i] += dx;
    }
    ll query(int L, int R) { return query(R) - query(L-1); }
    ll query(int i) {
        ll res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
};

int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> nums(N);
    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    BIT ft(nums);
    while (Q--) {
        int T, L, R;
        cin >> T >> L >> R;
        if (T == 1) ft.update(L-1, R);
        if (T == 2) cout << ft.query(L-1, R-1) << "\n";
    }
}
