#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ans = 0;
    int N; long long X; cin >> N >> X;
    vector<long long> pre(N+1);
    map<long long, int> count;
    count[0]++;
    for (int z = 1; z <= N; ++z) {
        int x; cin >> x;
        pre[z] = x + pre[z-1];
        long long diff = pre[z] - X;
        ans += count[diff];
        count[pre[z]]++;
    }
    cout << ans << endl;
}

// int N;
// int ans = 0;
// long long X;
// vector<long long> pre1, pre2;
//
// // TODO: return -1 if not there
// // TODO: account for indices before z
// //       STABLE SORT pre2 THEN BINARY SEARCH THE == X RANGE, store indices
// int binarySearch(int z, bool left) {
//     int lo = 0, hi = N+1;
//     if (pre2[z] - pre1[z-1] == X) {
//         ++ans; continue;
//     }
//     while (lo < hi) {
//         int mid = lo + (hi-lo)/2;
//         long long g = pre[mid] - pre[z-1];
//         if (left) {
//             if (g < X) lo = mid;
//             else hi = mid+1;
//         }
//         else {
//             if (g > X) hi = mid;
//             else lo = mid+1;
//         }
//     }
//     return lo;
// }
//
// int main() {
//     cin >> N >> X;
//     pre1.assign(N+1); pre2.assign(N+1);
//     for (int z = 1; z <= N; ++z) {
//         int x; cin >> x;
//         pre1[z] = x + pre1[z-1];
//         pre2[z] = pre1[z];
//     }
//     sort(begin(pre2), end(pre2));
//     for (int z = 1; z <= N; ++z) {
//         int a = binarySearch(z, true);
//         int b = binarySearch(z, false);
//         ans += b-a+1;
//     }
//     cout << ans << endl;
//
// }
