// Bitmask bfs. Floyd is faster probably.
class Solution {
public:
    int N;
    int done;
    bool seen[12][4096];

    int bfs(int s, vector<vector<int>>& graph) {
        int steps = 0;
        queue<pair<int, int>> q;
        q.push({s, 1<<s});
        while (!q.empty()) {
            int layer = q.size();
            for (int l = 0; l < layer; ++l) {
                auto [n, k] = q.front();  // k: visited nodes bitmask
                q.pop();
                if (k == done) return steps;
                if (seen[n][k]) continue;
                seen[n][k] = true;
                for (int e : graph[n]) {
                    if (seen[e][k]) continue;
                    int bm = k | (1 << e);
                    if (bm == done) return steps+1;
                    q.push({e, bm});
                }
            }
            ++steps;
        }
        return INT_MAX;
    }

    int shortestPathLength(vector<vector<int>>& graph) {
        N = graph.size();
        int ans = INT_MAX;
        done = (1 << N) - 1;
        for (int start = 0; start < N; ++start) {
            memset(seen, 0, sizeof seen);
            ans = min(ans, bfs(start, graph));
        }

        return ans;
    }
};
