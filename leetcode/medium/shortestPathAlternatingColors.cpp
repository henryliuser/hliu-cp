class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        int layer = 0;
        vector<int> ans(n, -1);
        vector<vector<int>> reds(n), blues(n);
        for (auto e : red_edges)
            reds[e[0]].push_back(e[1]);
        for (auto e : blue_edges)
            blues[e[0]].push_back(e[1]);
        queue<pair<int, int>> q;  // {x,c}  c = 1:blue, 2:red
        q.push({0, 1});
        q.push({0, 2});
        vector<vector<int>> seen(2, vector<int>(n));
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [x, c] = q.front();
                q.pop();
                if (ans[x] == -1) ans[x] = layer;
                ans[x] = min(ans[x], layer);
                if (c == 1)
                    for (int y : reds[x]) {
                        if (seen[1][y]) continue;
                        seen[1][y] = 1;
                        q.push({y, 2});
                    }
                if (c == 2)
                    for (int y : blues[x]) {
                        if (seen[0][y]) continue;
                        seen[0][y] = 1;
                        q.push({y, 1});
                    }
            }
            ++layer;
        }
        return ans;
    }
};
