class Solution {
public:
    struct Node {
        int time = -1;
        vector<int> list;
    };

    void dfs(int z, int path, int& ans, vector<Node>& graph) {
        Node& n = graph[z];
        if (n.list.size() > 0) {
            path += n.time;
            ans = max(ans, path);
            for (int& a : n.list)
                dfs(a, path, ans, graph);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        vector<Node> graph(n, Node());
        for (int z = 0; z < n; z++) {
            graph[z].time = informTime[z];
            if (manager[z] == -1) continue;
            graph[manager[z]].list.push_back(z);
        }
        dfs(headID, 0, ans, graph);
        return ans;
    }
};
