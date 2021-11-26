#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = array<int, 2>;

int main() {
    int N; cin >> N;
    vector<pii> A(N);
    for (pii &x : A)
        cin >> x[0] >> x[1];
    sort(begin(A), end(A));

    ll t = 0, ans = 0;
    for (pii &x : A) {
        t += x[0];
        ans += x[1] - t;
    }
    cout << ans << "\n";

}
