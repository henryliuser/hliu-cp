// https://atcoder.jp/contests/arc133/tasks/arc133_b
// PAIRS SUBSEQUENCE -> enumerate all possible pairs, then run
// Russian Doll Envelopes LIS on indices. crazy how that works
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pi(x) array<int,x>

set<int> factorize(int n) {
    set<int> f;
    for (int x = 1; x*x <= n; ++x)
        if (n % x == 0) {
            f.insert(n / x),
            f.insert(x);
        }
    return f;
}

bool cmp(pi(2) a, pi(2) b) {
    return a[0] < b[0] && a[1] < b[1];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    vector<int> P(N), Q(N);
    for (int &x : P) cin >> x;
    for (int &x : Q) cin >> x;

    map<int, int> idx;
    for (int i = 0; i < N; ++i)
        idx[ P[i] ] = i;

    vector<pi(2)> A;
    for (int j = 0; j < N; ++j) {
        int x = Q[j];
        for (int f : factorize(x)) {
            int i = idx[f];
            A.push_back( {i,j} );
        }
    }
    sort(begin(A), end(A), [](auto &a, auto &b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    vector<pi(2)> dp;
    for (auto &x : A) {
        auto it = lower_bound(begin(dp), end(dp), x, cmp);
        if (it == end(dp)) dp.push_back(x);
        else *it = x;
    }
    cout << dp.size() << '\n';
}
