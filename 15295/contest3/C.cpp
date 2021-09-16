#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = INT_MAX;
    int n; cin >> n;
    vector<int> dp(n);
    vector<pair<int, int>> beacons(n);
    for (int i = 0; i < n; ++i) {
        int pos, pow; cin >> pos >> pow;
        beacons[i] = {pos, pow};
    }
    sort(beacons.begin(), beacons.end());
    vector<int> pos(n), pow(n);
    for (int i = 0; i < n; ++i)
        pos[i] = beacons[i].first, pow[i] = beacons[i].second;

    for (int i = 1; i < n; ++i) {
        int target = pos[i] - pow[i];
        auto it = lower_bound(pos.begin(), pos.end(), target);
        if (it == pos.begin()) {
            dp[i] = i;
            continue;
        }
        --it;
        int idx = *it;
        printf("it: %d\n", idx);
        dp[i] = (i-idx-1) + dp[idx];
    }
    for (auto x : dp) printf("%d ", x); cout << endl;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, i + dp[n-i-1]);
    }
    cout << ans << endl;

}
