#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = array<ll, 2>;

int main() {
    int K, M, N;
    cin >> K >> M >> N;
    vector<pll> A(K);
    vector<ll>  B(M);
    for (pll &x : A) cin >> x[0] >> x[1];
    for (ll  &x : B) cin >> x;
    sort(begin(A), end(A));
    sort(begin(B), end(B));

    ll curr = 0;
    int i = 0, j = K-1;
    priority_queue<ll> pq;
    while (i < K && A[i][0] < B[0]) curr += A[i++][0];
    pq.push(curr);
    curr = 0;
    while (i < j && A[j][0] > B[M-1]) curr += A[j--][0];
    pq.push(curr);

    curr = 0;
    while (i < j) {
        // add i
        // if bad, split
        // else
        ++i;
    }

    N = min(N, pq.size());
    while (N--) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << "\n";

    // x..oooo.x
    // 01234567





}
