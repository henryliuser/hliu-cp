class Solution {
public:
    int N;
    vector<int> ngeq, nleq;
    vector<vector<short>> dp;

    void process(vector<int>& arr, vector<int>& res, bool leq) {
        map<int, vector<int>> seen;
        for (int i = 0; i < N; ++i) {
            int x = arr[i];
            if (leq) x *= -1;
            if (!seen.empty()) {
                auto it = seen.lower_bound(x);
                if (leq) it = next(it);
                else it = prev(it);
                int idx = (it->second).back();
                res[idx] = i;
            }
            seen[x].push_back(i);
        }
    }

    bool dfs(int x, bool odd, vector<int>& arr) {
        if (x == N-1) return true;
        if (dp[odd][x] != -1) return dp[odd][x];
        if (odd) {
            if (ngeq[x] == -1) dp[odd][x] = false;
            else dp[odd][x] = dfs(ngeq[x], false, arr);
        }
        else {
            if (nleq[x] == -1) dp[odd][x] = false;
            dp[odd][x] = dfs(nleq[x], true, arr);
        }
        return dp[odd][x];
    }

    int oddEvenJumps(vector<int>& arr) {
        int ans = 0;
        N = arr.size();
        ngeq.assign(N, -1);
        nleq.assign(N, -1);
        dp.assign(2, vector<short>(N, -1));

        process(arr, ngeq, false);
        process(arr, nleq, true);

        for (int i = 0; i < N; ++i)
            ans += dfs(i, true, arr);

        return ans;
    }
};
