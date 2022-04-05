// https://atcoder.jp/contests/abc245/tasks/abc245_e
// run 2 pointers on chocolates and boxes with multiset
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using pi = array<int, 2>;
#define rall(x) (x).rbegin(), (x).rend()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    vector<pi> A(N), B(M);
    for (pi &p : A) cin >> p[0];
    for (pi &p : A) cin >> p[1];
    for (pi &p : B) cin >> p[0];
    for (pi &p : B) cin >> p[1];
    sort( rall(A) ), sort( rall(B) );

    int i, j = 0;
    multiset<int> ms;
    for (i = 0; i < N; ++i) {
        pi a = A[i];
        while (j < M && B[j][0] >= a[0])
            ms.insert( B[j++][1] );

        auto it = ms.lower_bound(a[1]);
        if (it == end(ms)) break;
        ms.erase(it);
    }

    cout << (i==N ? "Yes" : "No") << '\n';

}
