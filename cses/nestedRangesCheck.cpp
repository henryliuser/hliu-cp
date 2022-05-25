// https://cses.fi/problemset/task/2168/
// sweepline
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using pi = array<int, 3>;
#define all(x) begin(x), end(x)

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    vector<pi> X(N), Y(N);
    vector<bool> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i][0] >> Y[i][0];
        Y[i][1] = -X[i][0];  // for ordering purpose
        X[i][1] = 0;
        X[i][2] = Y[i][2] = i;
    }

    set< pair<int,int> > s;
    sort( all(X) ), sort( all(Y) );

    for (int j=0, i=0; i < N; ++i) {
        auto [y, x, k] = Y[i];
        while (j < N && X[j][0] < y) {
            auto [xx, _, q] = X[j++];
            s.insert( {xx,q} );
        }
        s.erase( {-x,k} );
        auto it = begin(s);
        while (it != end(s) && it->first <= -x) {
            A[it->second] = true;
            it = s.erase(it);
        }
    }

    map<int, int> cur;
    for (int j=0, i=0; i < N; ++i) {
        auto [y, x, k] = Y[i];
        while (j < N && X[j][0] < y)
            ++cur[ X[j++][0] ];
        if (--cur[-x] <= 0) cur.erase(-x);
        B[k] = (!cur.empty() && begin(cur)->first <= -x);
    }
    for (auto &v : {A,B}) {
        for (bool x : v) cout << x << ' ';
        cout << '\n';
    }
}
