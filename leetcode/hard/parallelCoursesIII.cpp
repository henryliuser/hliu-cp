using pii = pair<int, int>;
#define f first
#define s second
class Solution {
public:
    vector<int> dp;
    vector<vector<int>> graph;

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> seen(n);
        vector<int> indeg(n);
        dp.assign(n, -1);
        graph.resize(n);
        for (auto &r : relations) {
            graph[r[0]-1].push_back(r[1]-1);
            ++indeg[r[1]-1];
        }
        int ans = 0;
        int left = n;
        queue<pii> q;
        for (int i = 0; i < n; ++i)
            if (indeg[i] == 0) {
                q.push({time[i], i});
                ans = max(ans, time[i]);
                --left;
            }
        if (!left) return ans;

        while (!q.empty()) {
            pii p = q.front();
            q.pop();
            for (int v : graph[p.s]) {
                ++seen[v];
                dp[v] = max(dp[v], p.f);
                if (seen[v] != indeg[v]) continue;
                --left;
                ans = max(ans, dp[v] + time[v]);
                if (!left) return ans;
                q.push({dp[v] + time[v], v});
            }
        }
        return ans;


    }
};
