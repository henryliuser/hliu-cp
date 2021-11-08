#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int ans = 0;
    int N = nums.size();
    vector<int> dp(N);
    for (int x : nums) {
        int lo = 0, hi = ans;
        while (lo < hi) {
            int mid = lo + (hi-lo) / 2;
            if (dp[mid] < x) lo = mid+1;
            else hi = mid;
        }
        dp[lo] = x;
        if (lo == ans) ans++;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> s(n);
    vector<int> q(n-1);
    for (int z = 0; z < n; ++z) cin >> s[z];
    for (int z = 0; z < n-1; ++z) q[z] = min(s[z], s[z+1]);
    cout << lengthOfLIS(q) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
