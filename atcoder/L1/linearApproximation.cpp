// https://atcoder.jp/contests/arc100/tasks/arc100_a
// let B[i] = A[i] - i, optimal b is median of b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<ll> A;

ll calc(ll b) {
    ll res = 0;
    for (int i = 1; i <= N; ++i) {
        ll x = A[i-1];
        res += abs(x - (b+i));
    }
    return res;
}

int main() {
    cin >> N; A.resize(N);
    for (ll &x : A) cin >> x;
    vector<ll> B(N);
    for (int i = 0; i < N; ++i)
        B[i] = A[i] - i-1;
    sort(begin(B), end(B));
    cout << calc(B[N/2]) << "\n";
}


// sketchy binary search on valley, AC
//
// ll calc(ll b) {
//     ll res = 0;
//     for (int i = 1; i <= N; ++i) {
//         ll x = A[i-1];
//         res += abs(x - (b+i));
//     }
//     return res;
// }
//
// int check(ll g) {
//     ll  left = calc(g-1);
//     ll  curr = calc(g);
//     ll right = calc(g+1);
//     if (curr == right || curr == left) return 1;  // sketchy, just a hunch
//     if (curr > right) return 2;
//     if (curr > left)  return 0;
//     if (left > curr && curr < right) return 1;
// }
//
// ll solve() {
//     ll lo = -1e18, hi = 1e18;
//     while (lo < hi) {
//         ll mid = (lo / 2) + (hi / 2) + ((lo % 2 + hi % 2) / 2);  // noverflow
//         int c = check(mid);
//         if (c == 0) hi = mid-1;
//         if (c == 1) return calc(mid);
//         if (c == 2) lo = mid+1;
//     }
//     return calc(lo);
// }
//
// int main() {
//     cin >> N; A.resize(N);
//     for (ll &x : A) cin >> x;
//
//     cout << solve() << "\n";
// }
