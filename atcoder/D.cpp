// https://atcoder.jp/contests/abc230/tasks/abc230_d
// tougher than i thought, but instructive. (though idk why mine is WA)
// optimal solution begins each punch at an end point
// greedily grab until you need to start a new punch.
// it doens't matter if you don't grab all the possible ones
// with the current punch, because they will Definitely
// be grabbed in later punches. That last realization is the hard part.
#include <bits/stdc++.h>
using namespace std;
using lr = array<int, 2>;

int main() {
    int ans = 1;
    int N, D; cin >> N >> D;
    vector<lr> A(N);
    for (lr &p : A)
        cin >> p[1] >> p[0];  // flipped
    sort(begin(A), end(A));

    int curr = A[0][0];
    for (int i = 1; i < N; ++i) {
        int dx = A[i][1] - curr + 1;
        if (dx > D) ++ans, curr = A[i][0];
    }
    cout << ans << "\n";

}

// Unsure why this one doesn't work.
// #include <bits/stdc++.h>
// using namespace std;
// using lr = array<int, 2>;
// using ll = long long;
//
// struct Window {
//     int req = 1;
//     bool dj = false;
//     lr curr = {-1, INT_MAX};
//     void add(lr p) {
//         if (p[0] > curr[1]) {
//             int left = (dj) ? curr[0] : curr[1];
//             req = p[0] - left + 1;
//             curr = {left, p[0]};
//             dj = true;
//             return;
//         }
//         curr[0] = max(curr[0], p[0]);
//         curr[1] = min(curr[1], p[1]);
//     }
//     void reset(lr p) {
//         req = 1;
//         curr = p;
//         dj = false;
//     }
// };
//
// int main() {
//     ll ans = 1;
//     ll N, D; cin >> N >> D;
//     vector<lr> A(N);
//     for (lr &p : A)
//         cin >> p[0] >> p[1];
//     sort(begin(A), end(A));
//
//     Window curr;
//     for (int j = 0; j < N; ++j) {
//         curr.add(A[j]);
//         if (curr.req > D) {
//             ++ans;
//             curr.reset(A[j]);
//         }
//     }
//     cout << ans << "\n";
//
// }
//
