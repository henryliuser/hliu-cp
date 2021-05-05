class Solution {
public:

    void dijkstra(int root, vector<int>& dist, vector<vector<pair<int, int>>>& graph)
    {
        dist[root] = 0;
        int N = dist.size();
        vector<bool> seen(N, false);
        for (int z = 0; z < N; z++) {
            int v = -1;
            for (int a = 0; a < N; a++)
                if (!seen[a] && (v == -1 || dist[a] < dist[v]))
                    v = a;
            if (dist[v] == INT_MAX) break;
            seen[v] = true;

            for (auto& edge : graph[v]) {
                int& target = dist[edge.first];
                int curr = dist[v] + edge.second;
                if (curr < target)
                    target = curr;
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = 0;
        vector<int> dist(n, INT_MAX);
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : times) {
            int from = edge[0]-1, to = edge[1]-1;
            int time = edge[2];
            graph[from].push_back( {to, time} );
        }

        dijkstra(k-1, dist, graph);
        for (int& d : dist) {
            ans = max(ans, d);
            if (ans == INT_MAX) return -1;
        }

        return ans;
    }
};
