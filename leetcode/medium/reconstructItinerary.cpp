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
    // int N;
    // bool first = true;
    // void dfs(string s, string from, vector<string>& path,
    //          unordered_map<string, map<string, int>>& graph)
    // {
    //     if (path.size() == N) throw path;
    //     if (from != "") graph[from][s]--;
    //     auto& m = graph[s];
    //     for (auto it : m) {
    //         string st = it.first;
    //         if (graph[s][st] > 0) {
    //             path.push_back(st);
    //             dfs(st, s, path, graph);
    //             path.pop_back();
    //         }
    //     }
    //     if (from != "") graph[from][s]++;
    // }
    //
    // vector<string> findItinerary(vector<vector<string>>& tickets) {
    //     N = tickets.size() + 1;
    //     unordered_map<string, map<string, int>> graph;
    //     for (auto& t : tickets) {
    //         graph[t[0]][t[1]]++;
    //     }
    //
    //     try { dfs("JFK", "", {"JFK"}, graph); }
    //     catch (vector<string>& v) { return v; }
    //     return vector<string>();
    // }
// };
