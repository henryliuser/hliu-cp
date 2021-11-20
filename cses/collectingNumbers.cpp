// O(n)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 1;
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    vector<int> A(N);
    unordered_map<int, int> idx;
    idx.reserve(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        idx[A[i]] = i;
    }
    int last = -1;
    for (int i = 1; i <= N; ++i) {
        if (idx[i] < last) ++ans;
        last = idx[i];
    }
    cout << ans << "\n";

}

// O(n log n) bs
//
// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
//     cin.tie(0);
//     ios::sync_with_stdio(0);
//     int ans = 1;
//     int N; cin >> N;
//     map<int, int> idx;
//     for (int i = 0; i < N; ++i) {
//         int x; cin >> x;
//         idx.insert({x, i});
//     }
//
//     int last = -1;
//     for (int i = 1; i <= N; ++i) {
//         int j = idx[i];
//         if (j < last) ++ans;
//         last = j;
//     }
//     cout << ans << "\n";
//
// }
