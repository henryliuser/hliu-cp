// https://leetcode.com/problems/minimum-time-to-finish-the-race/
// calculate best[x] = min time to complete x laps with a single tire
// knapsack over best[x]
// O(NM), N=len(A), M=numLaps
using ll = long long;
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("sse4")
class Solution {
public:
    const int inf = 1e9;
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int N = tires.size();
        vector<ll> best(numLaps+1, inf);
        for (int i = 0; i < N; ++i) {
            ll a = tires[i][0];
            ll x = tires[i][1];
            best[1] = min(best[1], a);

            ll cur = a;
            ll last = a;
            for (int j = 2; j <= numLaps; ++j) {
                ll b = (cur *= x);
                ll c = changeTime + a;
                last += min(b,c);
                if (c <= b) break;
                best[j] = min(best[j], last);
            }
        }

        vector<ll> dp(numLaps+1, inf);
        dp[0] = -changeTime;
        for (int i = 1; i <= numLaps; ++i) {
            ll x = best[i];
            for (int j = 0; j <= numLaps; ++j) {
                if (dp[j] == inf) continue;
                if (j+i > numLaps) continue;
                dp[j+i] = min(dp[j+i], changeTime + dp[j] + x);
            }

        }
        return dp[numLaps];
    }
};
