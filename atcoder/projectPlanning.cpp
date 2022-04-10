#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

int N, K;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    vector<ll> A(N);
    for (ll &x : A) cin >> x;
    sort(begin(A), end(A));

    int ans = 0;
    int i = 0, k = 0;
    while (i < N-K) {
        while (i < N-K && A[i]-k < 0) ++i;
        k += A[i]-k;
        ans += A[i]-k;
    }
    cout << ans << '\n';

}
