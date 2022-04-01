// https://codeforces.com/problemset/problem/1660/F2
// treat '+' as 1, '-' as -1
// each operation increases sum by 3. (+1, - -2)
// ignore adjacent constraint. it's not relevant
// because any subarray with negative sum <= -3 will have adjacent '-'s
// task is reduced to:
// count number of subarray sums divisible by 3, that are NEGATIVE
// because we want an excess of '-'s.
// use a bit for all psums under % 3
// update/query the bit for our current psum `cur` % 3
// count previous occurrences of psums >= cur with bit
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

int N;
string S;

struct BIT {
    int n;
    vector<ll> bit;
    BIT() : n(2*N+1), bit(2*N+5) {}  // all values + N for negative indexing
    void upd(int i, ll val) {
        for (++i; i <= n; i += i & -i)
            bit[i] += val;
    }
    ll qry(int i, int j) { return qry(j) - qry(i-1); }
    ll qry(int i) {
        ll res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
};

ll solve() {
    cin >> N >> S;

    BIT ft[3];        // each 1 already initialized to (2*N+1) size
    ft[0].upd(N, 1);  // bit[0] = 1;

    ll ans = 0;
    int cur = 0;  // prefix sum
    for (int i = 0; i < N; ++i) {
        int x = (S[i] == '+') ? 1 : -1;
        cur += x;
        int j = (cur%3+3) % 3;
        int idx = cur+N;  // index with offset
        ans += ft[j].qry(idx, 2*N);
        ft[j].upd(idx, 1);
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
