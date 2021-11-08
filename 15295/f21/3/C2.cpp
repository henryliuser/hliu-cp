#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = INT_MAX;
    int n; cin >> n;
    vector<int> dp(n);
    map<int, pair<int, int>> beacons;
    for (int i = 0; i < n; ++i) {
        int pos, pow; cin >> pos >> pow;
        beacons[pos] = {i, pow};
    }
    auto ite = beacons.begin();
    for (int i = 1; i < n; ++i) {
        ++ite;
        if (ite->second.second == 0) {
            dp[i] = dp[i-1];
            continue;
        }
        int target = ite->first - ite->second.second;

        auto it = beacons.lower_bound(target);
        if (it == beacons.begin()) {
            dp[i] = i-1;
            continue;
        }
        --it;
        int idx = it->second.first;
        // printf("idx: %d\n", idx);
        dp[i] = (i-idx-1) + dp[idx];
    }
    // for (auto x : dp) printf("%d ", x); cout << endl;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, i + dp[n-i-1]);
    }
    cout << ans << endl;

}
