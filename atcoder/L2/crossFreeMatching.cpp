// https://atcoder.jp/contests/arc126/tasks/arc126_b
// russian doll envelopes from leetcode.

// Solution:
// sort ascending by A, descending by B
// LIS dp over B,
// OR: dp over AB with cmp(x, y) = x.a < y.a && x.b < y.b
// 2nd one more intuitive

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = array<int, 2>;

bool cmp(pi a, pi b) {  // for sort
    if (a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}
bool cmp2(pi a, pi b) {  // for lower_bound
    return a[0] < b[0] && a[1] < b[1];
}

int main() {
    int N, M; cin >> N >> M;
    vector<pi> A(M);
    for (pi &p : A)
        cin >> p[0] >> p[1];

    vector<pi> dp;
    sort(begin(A), end(A), cmp);
    for (pi &p : A) {
        auto it = lower_bound(begin(dp), end(dp), p, cmp2);
        if (it == end(dp)) dp.push_back(p);
        else *it = p;
    }
    cout << dp.size() << "\n";

}
