class Solution {
public:
    int time, X; // seconds, target
    void dfs(int z, double prob, int t, int parent,
             vector<vector<int>>& graph, vector<bool>& seen)
    {
        int len = graph[z].size() - 1; // excluding parent
        if (z == 0) len += 1; // the root
        seen[z] = true;
        if (z == X) {
            double ans;
            if (t == time) ans = prob;
            else if (t < time && len == 0) ans = prob;
            else ans = 0;
            throw ans; // exit recursion
        }
        for (int a = 0; a < graph[z].size(); a++) {
            int b = graph[z][a];
            if (!seen[b] && b != parent)
                dfs(b, prob/len, t+1, z, graph, seen);
        }
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        time = t, X = target-1;
        vector<bool> seen(n);
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            int a = e[0]-1, b = e[1]-1;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        try { dfs(0, 1.0, 0, -1, graph, seen); }
        catch (double ans) { return ans; }
        return 0.0;
    }
};
