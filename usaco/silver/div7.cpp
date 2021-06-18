#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

}


// void badSolution() {   // barely runs in time (1870 ms)
//     int N; cin >> N;
//     vector<long long> pre(N+1);
//     for (int z = 1; z <= N; z++) {
//         cin >> pre[z];
//         pre[z] += pre[z-1];
//     }
//     int ans = 0;
//     try {
//         for (int g = N; g > 0; g--)
//             for (int a = 0; a < N-g; a++) {
//                 if ((pre[a+g] - pre[a]) % 7 == 0){
//                     ans = g;
//                     throw -1;
//                 }
//             }
//
//     }
//     catch (...) {}
//
//     cout << ans << endl;
// }
