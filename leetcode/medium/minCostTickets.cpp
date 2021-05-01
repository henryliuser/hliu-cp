class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int dp[366];
        for (int z = 0; z < 366; z++) dp[z] = INT_MAX;
        dp[0] = 0;
        int passes[] = {1,7,30};
        int idx = 0, last = days.back();
        for (int d = 1; d <= last; d++) {
            if (days[idx] != d) { dp[d] = dp[d-1]; continue; }
            else idx++;
            for (int c = 0; c < 3; c++) {
                int pa = passes[c];
                int cs = costs[c];
                dp[d] = min(dp[d], dp[max(d-pa, 0)]+cs);
            }
        }
        return dp[last];

    }
};
