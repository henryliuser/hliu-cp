// https://codeforces.com/contest/1398/problem/C
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// instructive problem :)
// pre[r] - pre[l] = r - l + 1
// pre[r] - r = pre[l] - l + 1   move same vars to same side
// so: count unique (i,j) such that pre[i]-i == pre[j]-j
// hash on pre[i]-i

ll solve() {
    ll ans = 0;
    int n; cin >> n;
    string v; cin >> v;
    unordered_map<int, ll> count;
    count[0] = 1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x = v[i] - '0';
        sum += x;
        int val = sum - i - 1;
        ans += count[val]++;
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << endl;
}

// don't actually need prefix sum, just running sum
//
// ll solve() {
//     ll ans = 0;
//     int n; cin >> n;
//     string v; cin >> v;
//     vector<ll> pre(n+1, 0);
//     unordered_map<ll, ll> count;
//     for (int i = 1; i <= n; ++i) {
//         int x = v[i-1] - '0';
//         pre[i] = pre[i-1] + x;
//     }
//     for (int i = 0; i <= n; ++i) {  // start 0, so that count[0] = 1
//         int val = pre[i] - i;
//         ans += count[val]++;
//     }
//     return ans;
// }
