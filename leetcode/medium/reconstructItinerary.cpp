// eulerian path
class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> result;
    void dfs(string vtex)
    {
        auto& edges = graph[vtex];
        while (!edges.empty()) {
            string to_vtex = edges.top();
            edges.pop();
            dfs(to_vtex);
        }
        result.push_back(vtex);
    }

    vector<string> findItinerary(vector<vector<string>> tickets) {
        for (auto e : tickets)
            graph[e[0]].push(e[1]);
        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};

// backtracking
class Solution {
public:
    int N;
    unordered_map<string, map<string, int>> graph;

    void dfs(string a, vector<string>& path) {
        path.push_back(a);
        if (path.size() == N+1) throw -1;
        for (auto& s : graph[a]) {
            if (!s.second) continue;
            s.second--;
            dfs(s.first, path);
            s.second++;  // backtrack
        }
        path.pop_back();  // backtrack
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        N = tickets.size();
        vector<string> ans;
        for (auto& t : tickets)
            graph[t[0]][t[1]]++;

        try { dfs("JFK", ans); }
        catch (int x) { }
        return ans;

    }
};
