// https://atcoder.jp/contests/abc253/tasks/abc253_f
// great question. had the persistent seg tree intuition right away
// but u can just do it offline way faster
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

#define ti(x) array<ll, x>

struct BIT {
    int N;
    vector<ll> bit;
    BIT(int n) : N(n), bit(n+1) {}
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

    int N, M, Q;
    cin >> N >> M >> Q;

    int version = 0;
    vector<ti(4)> R(Q);
    map<int, ll> mp;
    map<int, vector<ti(2)>> need;
    for (ll t,i,j,x, q=0; q < Q; ++q) {
        cin >> t;
        if (t == 1) {
            cin >> i >> j >> x;
            R[q] = {t,i,j,x};
            ++version;
        }
        if (t == 2) {
            cin >> i >> x;
            mp[i] = version;
            R[q] = {t,i,version,x};
        }
        if (t == 3) {
            cin >> i >> j;
            R[q] = {t,i,j,0};
            if (!mp.count(i)) continue;
            int v = mp[i];
            need[v].push_back( {j,q} );
        }
    }

    BIT ft(M+5);
    mp.clear();
    version = 0;
    vector<ll> supply(Q);
    for (int q = 0; q < Q; ++q) {
        auto [t,i,j,x] = R[q];
        if (t == 1) {
            ft.update(i, x);
            ft.update(j+1, -x);
            int v = ++version;
            for (auto [y,z] : need[v])
                supply[z] = ft.query(y);
        }
        if (t == 2) {
            mp[i] = x;
        }
        if (t == 3) {
            ll res = mp[i] + ft.query(j) - supply[q];
            cout << res << '\n';
        }
    }

}
