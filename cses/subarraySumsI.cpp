#include <bits/stdc++.h>
using namespace std;

// true O(N) sliding window
int main() {
    long long ans = 0;
    int N; long long X; cin >> N >> X;
    vector<long long> v(N);
    int i = 0;
    long long window = 0;
    for (int j = 0; j < N; ++j) {
        cin >> v[j];
        window += v[j];
        while (window >= X) {
            if (window == X) ++ans;
            window -= v[i++];
        }
    }
    cout << ans << endl;
}


// O(N) hash map but use n log n map due to CSES anti-hash cases

// int main() {
//     long long ans = 0;
//     int N; long long X; cin >> N >> X;
//     vector<long long> pre(N+1);
//     map<long long, int> count;
//     count[0]++;
//     for (int z = 1; z <= N; ++z) {
//         int x; cin >> x;
//         pre[z] = x + pre[z-1];
//         long long diff = pre[z] - X;
//         ans += count[diff];
//         count[pre[z]]++;
//     }
//     cout << ans << endl;
// }


// also instructive. Prefix sum is strictly increasing
// can binary search over the remaining indices.

// int main() {
//     int ans = 0;
//     int N; long long X; cin >> N >> X;
//     vector<long long> pre(N+1);
//     for (int z = 1; z <= N; ++z) {
//         int x; cin >> x;
//         pre[z] = x + pre[z-1];
//     }
//     for (int z = 1; z <= N; ++z) {
//         int lo = z, hi = N+1;
//         if (pre[z] - pre[z-1] == X) {
//             ++ans; continue;
//         }
//         while (lo < hi) {
//             int mid = lo + (hi-lo)/2;
//             long long g = pre[mid] - pre[z-1];
//             if (g == X) {
//                 ++ans;
//                 break;
//             }
//             else if (g < X) lo = mid+1;
//             else hi = mid;
//         }
//     }
//     cout << ans << endl;
//
// }
