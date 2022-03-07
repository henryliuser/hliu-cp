// https://cses.fi/problemset/task/1749
// bit to keep track of removed entries
// binary search the bit 
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

struct BIT {
    int n;
    vector<int> T;
    BIT(int n) : n(n), T(n+1) {}
    int qry(int i) {
        int res = 0;
        for (++i; i > 0; i -= i&-i)
            res += T[i];
        return res;
    }
    void upd(int i) {
        for (++i; i <= n; i += i&-i)
            ++T[i];
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    vector<ll> A(N);
    for (ll &x : A) cin >> x;
    BIT ft(N);
    for (int j, i=0; i < N; ++i) {
        cin >> j;
        int lo = 0, hi = N-1;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            int q = ft.qry(mid);
            if (mid+1-q >= j) hi = mid;
            else lo = mid+1;
        }
        cout << A[lo] << ' ';
        ft.upd(lo);
    }
    cout << '\n';
}
