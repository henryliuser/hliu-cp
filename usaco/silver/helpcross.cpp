#include <bits/stdc++.h>
using namespace std;
// O(N log N) greedy match 2 pointers?
int main() {
    // freopen("helpcross.in", "r", stdin);
    // freopen("helpcross.out", "w", stdout);
    int C, N; cin >> C >> N;
    vector<int> T(C);
    vector<pair<int, int>> cows(N);
    for (int z = 0; z < C; ++z)
        cin >> T[z];
    for (int z = 0; z < N; ++z)
        cin >> cows[z].first >> cows[z].second;

    sort(T.begin(), T.end());
    sort(cows.begin(), cows.end(), [](auto& a, auto& b) {
        if (a.first < b.first) return true;
        if (a.second < b.second) return true;
        return false;
    });

    int ans = 0;
    int i = 0, j = 0;  // i: chickens,  j: cows
    while (i < C && j < N) {
        printf("%d %d: ", i, j);
        int t = T[i];
        auto& c = cows[j];
        int a = c.first, b = c.second;
        if (a <= t && t <= b) {
            ++ans, ++i, ++j;
        }
        if (a > t) ++i;
        if (b < t) ++j;
        printf("%d\n", ans);
    }

    cout << ans << endl;

}
