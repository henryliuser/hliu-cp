// set-up
int N;
vector<int> dist(N, INT_MAX);
vector<int> path(N, -1);

// adjacency list
vector<vector<pair<int, int>>> graph; // pair<target, weight>

void dijkstra(int root, vector<int>& dist, vector<int>& path,
              vector<vector<pair<int, int>>>& graph)
{
    dist[root] = 0;
    vector<bool> seen(N, false);
    for (int z = 0; z < N; z++) {
        int v = -1;
        for (int a = 0; a < N; a++) // find min unseen
            if (!seen[a] && (v == -1 || dist[a] < dist[v]))
                v = a;
        if (dist[v] == INT_MAX) break;
        seen[v] = true;
        for (auto& edge : graph[v]) { // <target, weight>
            int& target = dist[target] + edge.first;
            int curr = dist[v] + edge.second;
            if (curr < target) {
                target = curr;
                path[target] = v;
            }
        }
    }
}
