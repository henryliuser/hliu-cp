#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;
    int N; cin >> N;
    vector<long long> pre(N+1);
    vector<long long> count(N);
    count[0]++;
    for (int z = 1; z <= N; ++z) {
        long long q; cin >> q;
        pre[z] = (q%N+N) % N + pre[z-1];
        pre[z] %= N;
        ans += count[pre[z]]++;
    }
    cout << ans << endl;

}
