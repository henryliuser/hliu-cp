class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<pair<vector<int>, int>> graph(numCourses);
        for (auto p : prerequisites) {
            cout << p[0] << endl;
            graph[p[1]].first.push_back(p[0]);
            graph[p[0]].second++;
        }
        queue<int> q;
        for (int z = 0; z < numCourses; z++)
            if (!graph[z].second) q.push(z);

        vector<bool> seen(numCourses);
        int count = 0;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            if (seen[t]) continue;
            seen[t] = true; count++;
            if (count == numCourses) return true;
            for (int a : graph[t].first)
                if (--graph[a].second == 0)
                    q.push(a);
        }
        return count == numCourses;
    }
};
