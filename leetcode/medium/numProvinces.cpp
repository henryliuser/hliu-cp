class Solution {
public:
    struct DSU {
        int count;
        vector<int> parent;
        vector<int> size; // Union by Size

        DSU(int N) : count(N), parent(N), size(N, 1) {
            for (int z = 0; z < N; z++) parent[z] = z;
        }

        void Union(int a, int b) {
            a = Find(a);
            b = Find(b);
            if (a != b) {
                if (size[a] < size[b]) swap(a, b);
                parent[b] = a;
                size[a] += size[b];
                count--;
            }
        }

        int Find(int v) {
            if (v == parent[v]) return v;
            return parent[v] = Find(parent[v]);
        }   // path compression
    };

    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int N = isConnected.size();

        DSU uf{N};
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++) {
                if (isConnected[r][c])
                    uf.Union(r, c);

        return uf.count;
    }

    // Easy DFS
    // int n;
    // void dfs(int z, vector<vector<int>>& isConnected, vector<bool>& seen) {
    //     seen[z] = true;
    //     for (int a = 0; a < n; a++) {
    //         if (isConnected[z][a] && !seen[a])
    //             dfs(a, isConnected, seen);
    //     }
    // }
    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int ans = 0;
    //     n = isConnected.size();
    //     vector<bool> seen(n);
    //     for (int z = 0; z < n; z++)
    //         if (!seen[z]) {
    //             ans++;
    //             dfs(z, isConnected, seen);
    //         }
    //     return ans;
    // }
};
