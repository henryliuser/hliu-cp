#include <bits/stdc++.h>
using namespace std;
using pi = array<int, 2>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<pi> A;
    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        A.push_back( {b, a} );
    }

    int ans = 0;
    multiset<int> ms;
    for (int i = 0; i < K; ++i)
        ms.insert(-1);
    sort(begin(A), end(A));
    for (int i = 0; i < N; ++i) {
        pi p = A[i];
        auto it = ms.upper_bound(p[1]); // upper bound to keep earlier finishers free-er 
        if (it == begin(ms)) continue;  // check for available member
        ms.erase(--it);
        ms.insert(p[0]);  // insert end time
        ++ans;
    }

    cout << ans << "\n";

}
