class Solution {
public:

    bool dfs(int z, vector<vector<int>>& graph, vector<int>& seen) {
        if (seen[z] == 1) return false;
        if (seen[z] == 2) return true;
        int count = graph[z].size();
        seen[z] = 1;
        for (int& a : graph[z])
            if (dfs(a, graph, seen))
                    count--;

        if (count == 0) seen[z] = 2;
        return count == 0;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> seen(N); // 0:unseen, 1:seen & unasfe, 2:seen & safe
        for (int z = 0; z < N; z++) {
            if (!seen[z])
                dfs(z, graph, seen);
        }
        vector<int> ans;
        for (int z = 0; z < N; z++)
            if (seen[z] == 2)
                ans.push_back(z);
        return ans;

    }
};
