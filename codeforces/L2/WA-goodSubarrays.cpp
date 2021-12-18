// https://codeforces.com/contest/1398/problem/C
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int solve() {
    int ans = 0;
    int n; cin >> n;
    string v; cin >> v;
    vector<int> pre(n+1);
    vector<int> dp0L(n+1), dp1L(n+1), dp0R(n+1), dp1R(n+1);
    // dp0L[i] = # of good subarrays ending at i (from left)
    // dp1L[i] = # of ALMOST good subarrays ending at i (from left)
    // dpxR is from right
    for (int i = 1; i <= n; ++i) {
        int x = v[i-1] - '0';
        pre[i] = pre[i-1] + x;
        if (x == 1) {
          dp0L[i] = 1;
          dp1L[i] = dp1L[i-1];
        }
        if (x == 2) dp1L[i] = 1 + dp0L[i-1];
        if (x <= i) {
            int ps = pre[i] - pre[i-x];
            if (ps <= i)
                dp0L[i] += dp0L[i-ps];
        }
        if (x == 0) ans += dp1L[i-1];
        ans += dp0L[i];
    }
    for (int i = n-1; i >= 0; --i) {
      int x = v[i-1] - '0';
      if (x == 1) {
        dp0R[i] = 1;
        dp1R[i] = dp1R[i+1];
      }
      if (x == 2) dp1R[i] = 1 + dp0R[i+1];
      if (x <= n-1-i) {
        int ps = pre[i] - pre[i+x];
        if (ps <= n-1-i)
          dp0R[i] += dp0R[i+ps];
      }
      if (x == 0) ans += dp1R[i+1];
    }
    return ans;
}

int main() {

    int t; cin >> t;
    while (t--)
        cout << solve() << endl;

}
