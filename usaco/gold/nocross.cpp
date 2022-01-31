// http://www.usaco.org/index.php?page=viewproblem2&cpid=718
// 9N log(9N)
// vs. LCS version: N^2
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = array<int, 2>;

bool cmp(pi a, pi b) {
    return a[0] < b[0] && -a[1] < -b[1];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);

    int N; cin >> N;
    map<int, int> A;
    vector<int> B;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        A[x] = i;
    }
    vector<pi> P;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        for (int y = max(0,x-4); y <= x+4; ++y)
            if (A.count(y))
                P.push_back( {A[y], -i} );
    }
    sort(begin(P), end(P));

    vector<pi> dp;
    for (pi &x : P) {
        auto it = lower_bound(begin(dp), end(dp), x, cmp);
        if (it == end(dp)) dp.push_back(x);
        else *it = x;
    }
    cout << dp.size() << '\n';


}
