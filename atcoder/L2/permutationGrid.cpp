// very instructive.
// https://atcoder.jp/contests/arc132/tasks/arc132_a
// recover some original after transformation:
// start with some base case, and apply transformations
// then work backwards.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, Q, r, c;
int main() {
    cin >> N;
    vector<int> R(N), C(N);
    for (int &x : R) cin >> x;
    for (int &x : C) cin >> x;
    cin >> Q;
    while (Q--) {
        cin >> r >> c;
        r = R[r-1], c = C[c-1];
        if (r + c >= N+1) cout << "#";
        else cout << ".";
    }
    cout << "\n";
}
