#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    ll ans = 0;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    int q = A[n/2];
    for (int i = 0; i < n; ++i)
        ans += abs(A[i] - q);
    cout << ans << endl;
}
