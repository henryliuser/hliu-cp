#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int N, K, B; cin >> N >> K >> B;
    vector<int> pre(N+1);
    vector<int> broke(B);
    for (int z = 0; z < B; ++z)
        cin >> broke[z];
    sort(broke.begin(), broke.end());
    int bc = 0;
    for (int z = 1; z <= N; ++z)
        pre[z] = pre[z-1] + (z == broke[bc] && ++bc);

    int ans = B;
    for (int z = 0; z < N-K+1; ++z)  // iterate with window size K
        ans = min(ans, pre[z+K] - pre[z]);  // O(1) window query with psum

    cout << ans << endl;
}
