// https://atcoder.jp/contests/abc210/tasks/abc210_e
// solution: https://atcoder.jp/contests/abc210/editorial/2307
// really good question. We use kruskal's by calculating the # of new edges added
// per operation. We can do this by comparing the number of connected components
// in each graph. Recognize the congruence with gcd
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using pi = array<ll, 2>;
#define all(x) begin(x), end(x)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<pi> A(M);
    for (pi &p : A) cin >> p[1] >> p[0];
    sort( all(A) );

    ll g = N;    // number of connected components in previous G
    ll ans = 0;
    for (int i = 0; i < M; ++i) {
        if (g == 1) break;
        auto [c,x] = A[i];
        ll p = gcd(g, x);
        ans += (g - p) * c;
        g = p;
    }
    if (g != 1) ans = -1;
    cout << ans << '\n';
}
