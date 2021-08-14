#include <bits/stdc++.h>
using namespace std;
bool db = false;
int main() {
    int ans = 0;
    int N; long long X; cin >> N >> X;
    vector<long long> pre(N+1);
    for (int z = 1; z <= N; ++z) {
        int x; cin >> x;
        pre[z] = x + pre[z-1];

    for (int z = 1; z <= N; ++z) {
        int lo = z, hi = N+1;
        if (pre[z] - pre[z-1] == X) {
            ++ans; continue;
        }
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            long long g = pre[mid] - pre[z-1];
            if (g == X) {
                ++ans;
                break;
            }
            else if (g < X) lo = mid+1;
            else hi = mid;
        }
    }
    cout << ans << endl;

}
