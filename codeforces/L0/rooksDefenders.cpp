// https://codeforces.com/contest/1679/problem/C
// rmq
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
#define  ll long long

struct BIT {
    int N;
    vector<int> bit;
    BIT(int n) : N(n), bit(n+1) {}
    void update(int i, int val) {
        for (++i; i <= N; i += i & -i)
            bit[i] += val;
    }
    inline int query(int L, int R) { return query(R) - query(L-1); }
    inline int query(int i) {
        int res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
};

#define answer(x) {      \
    cout << x << '\n';   \
    continue;            \
}

const int MXN = 1e5+1;
int rx[MXN]{}, cx[MXN]{};

signed main() {
    int t, x1, y1, x2, y2;
    cin.tie(0)->sync_with_stdio(0);
    int N, Q;
    cin >> N >> Q;
    BIT row(N+1), col(N+1);
    for (int i = 0; i < Q; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> x1 >> y1;
            if (++rx[x1] == 1) row.update(x1, 1);
            if (++cx[y1] == 1) col.update(y1, 1);
        }
        if (t == 2) {
            cin >> x1 >> y1;
            if (--rx[x1] == 0) row.update(x1, -1);
            if (--cx[y1] == 0) col.update(y1, -1);
        }
        if (t == 3) {
            cin >> x1 >> y1 >> x2 >> y2;
            if (row.query(x1, x2) == (x2-x1+1)) answer("Yes");
            if (col.query(y1, y2) == (y2-y1+1)) answer("Yes");
            answer("No");
        }
    }
}
