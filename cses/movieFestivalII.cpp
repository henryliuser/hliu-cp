#include <bits/stdc++.h>
using namespace std;
using tup = array<int, 2>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<tup> A;
    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        A.push_back( {b, a} );
    }

    int t = 0, ans = 0;
    multiset<int> ends;
    for (int i = 0; i < K; ++i)
        ends.insert(0);

    sort(begin(A), end(A));
    for (tup &e : A) {
        auto it = ends.upper_bound(e[1]);
        if (it == begin(ends)) continue;
        ends.erase(--it);
        ends.insert(e[0]);
        ++ans;
    }

    cout << ans << "\n";

}
