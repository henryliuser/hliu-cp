// O(N) 2p
#include <bits/stdc++.h>
using namespace std;

int N, Q;
string A;
unordered_map<char, int> cnt;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int ans = INT_MAX;
    cin >> N >> A;
    for (char ch : A) ++cnt[ch];
    Q = cnt.size();

    int i = 0;
    cnt.clear();
    for (int j = 0; j < N; ++j) {
        ++cnt[A[j]];
        while (cnt.size() == Q) {
            ans = min(ans, j-i+1);
            if (--cnt[A[i++]] == 0)
                cnt.erase(A[i-1]);
        }
    }
    cout << ans << "\n";
}


// O(N log N) binary search
//
// #include <bits/stdc++.h>
// using namespace std;
//
// int N;
// string A;
// unordered_map<char, int> cnt;
//
// bool check(int g, int uq) {
//     cnt.clear();
//     for (int i = 0; i < g; ++i) {
//         ++cnt[ A[i] ];
//         if (cnt.size() == uq) return 1;
//     }
//     for (int i = g; i < N; ++i) {
//         ++cnt[ A[i] ];
//         if (--cnt[ A[i-g] ] == 0)
//             cnt.erase(A[i-g]);
//         if (cnt.size() == uq) return 1;
//     }
//     return 0;
// }
//
// int main() {
//     cin.tie(0);
//     ios::sync_with_stdio(0);
//     cin >> N >> A;
//     for (char ch : A) ++cnt[ch];
//     int uq = cnt.size();
//     int lo = 1, hi = N;
//     while (lo < hi) {
//         int mid = lo + (hi-lo) / 2;
//         if (check(mid, uq)) hi = mid;
//         else lo = mid + 1;
//     }
//     cout << lo << "\n";
// }
