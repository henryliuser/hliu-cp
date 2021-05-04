class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<pair<vector<int>, int>> graph(numCourses); // (adjacency list, in-degree)
        for (auto p : prerequisites) {
            int a = p[0], b = p[1];
            graph[b].first.push_back(a);
            graph[a].second++;
        }
        queue<int> q;
        for (int z = 0; z < numCourses; z++)
            if (graph[z].second == 0)
                q.push(z);

        while (!q.empty()) {
            int a = q.front(); q.pop();
            ans.push_back(a);
            auto p = graph[a];
            for (int c : p.first) {
                if (--graph[c].second == 0)
                    q.push(c);
            }
        }
        if (ans.size() != numCourses) return vector<int>(0);
        return ans;

    }
};
