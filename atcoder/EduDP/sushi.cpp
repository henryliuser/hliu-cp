// https://atcoder.jp/contests/dp/tasks/dp_j
// original straightforward transition has a loop in transitions!
// if N dishes and K of them have at least one sushi,
// then K = x + y + z, and
// probability of transitioning to a new state is K/N,
// so EV of number of rolls before transitioning is N/K.
// dp[x][y][z] =
//     (N/K + dp[x-1][y][z])   * x/K
//   + (N/K + dp[x+1][y-1][z]) * y/K
//   + (N/K + dp[x][y+1][z-1]) * z/K
//
// this simplifies down to:
// dp[x][y][z] = (N + x(dp_1) + y(dp_2) + z(dp_3)) / K
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
double dp[301][301][301];
// dp[x][y][z] = EV for
// x 1-plates, y 2-plates, z 3-plates

double dfs(int x, int y, int z) {
    double K = x + y + z;
    if (K == 0) return 0;
    if (x < 0 || y < 0 || z < 0) return 0;
    double &res = dp[x][y][z];
    if (res > -0.5) return res;  // float comparison

    res = N/K;  // N/K = EV of # of rolls before transitioning to new state
    // ^^ need to do this to avoid loop in recurrence
    res += dfs(x-1,  y,  z) * x/K;  // EV of hitting x, weighted by P(x)
    res += dfs(x+1, y-1, z) * y/K;  // EV of hitting y, weighted by P(y)
    res += dfs(x, y+1, z-1) * z/K;  // EV of hitting z, weighted by P(z)

    // can do single division by K at the end,
    // which is noticeably faster but less intuitive imo
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    int cnt[4] = {};
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        ++cnt[x];
    }
    memset(dp, -1, sizeof dp);
    cout << fixed << setprecision(10);
    cout << dfs(cnt[1], cnt[2], cnt[3]) << '\n';
}


// troll approximation
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
//
// int main() {
//     int cnt = 0;
//     int N; cin >> N;
//     vector<int> A(N);
//     for (int &x : A) {
//         cin >> x;
//         cnt += x;
//     }
//
//     random_device rd;
//     mt19937 gen(rd());
//     uniform_int_distribution<> dist(0, N-1);
//
//     int iters = 300000;
//     long double ans = 0.0;
//     while (iters--) {
//         double res = 0;
//         int cur = cnt;
//         vector<int> B = A;
//         while (cur) {
//             int i = dist(gen);
//             if (B[i]-- > 0) --cur;
//             ++res;
//         }
//         ans += res;
//     }
//     cout << fixed << setprecision(10);
//     cout << ans / 300000.0 << '\n';
//
// }
