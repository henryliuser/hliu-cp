// https://cses.fi/problemset/task/2163
// binary search a BIT, until u find the element
// that's K "remaining" away
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

struct BIT {
    int N;
    vector<int> bit;
    BIT(int n) : N(n), bit(n+1) {
        for (int i = 0; i < n; ++i)
            update(i, 1);
    }
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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    BIT ft(N);
    int cur = 0;
    for (int x, q, i=0; i < N; ++i) {
        int t = K % (N-i) + 1;
        int l = 0, r = N;
        while (l < r) {
            int m = (l+r) >> 1;
            int v = (cur+m) % N;
            if (v >= cur) x = ft.query(cur, v);
            else x = ft.query(cur,N-1) + ft.query(0,v);
            if (x >= t) r = m, q = v;
            else l = m+1;
        }
        cur = q;
        ft.update(q, -1);
        cout << q+1 << ' ';
    }
}
