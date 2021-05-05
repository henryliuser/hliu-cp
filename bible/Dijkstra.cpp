// set-up
int N;
vector<int> dist(N, INT_MAX);
vector<int> path(N, -1);

// adjacency list
vector<vector<pair<int, int>>> graph; // pair<target, weight>

void dijkstra(int root, vector<int>& dist, vector<int>& path,
              vector<vector<pair<int, int>>>& graph)
{
    vector<bool> seen(N, false);
    dist[root] = 0;
    for (int z = 0; z < N; z++) {
        int v = -1;
        for (int a = 0; a < N; a++) // find min unseen
            if (!seen[a] && (v == -1 || dist[a] < dist[v]))
                v = j;
        if (dist[v] == INT_MAX) break;
        seen[v] = true;
        for (auto edge : graph[v]) {
            int target = edge.first;
            int weight = edge.second;
            if (dist[v] + weight < dist[target]) {
                dist[target] = dist[v] + weight;
                path[target] = v;
            }
        }
    }
}
