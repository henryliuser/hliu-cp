#include <bits/stdc++.h>
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
    vector<ll> A = {6,1,2,3,4,5,6};
    BIT bit(A);
    cout << bit.query(4) - bit.query(2) << endl;
    bit.update(4, 3);
    cout << bit.query(6) - bit.query(3) << endl;
    cout << bit.query(-1) << endl;
}
