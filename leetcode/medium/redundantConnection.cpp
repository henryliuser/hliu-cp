class Solution {
public:
    struct DSU {
        int count;
        vector<int> parent;
        vector<int> size; // Union by Size

        DSU(int N) : count(N), parent(N), size(N, 1) {
            for (int z = 0; z < N; z++) parent[z] = z;
        }

        bool Union(int a, int b) { // return on success
            a = Find(a);
            b = Find(b);
            if (a == b) return false; // cycle
            else {
                if (size[a] < size[b]) swap(a, b);
                parent[b] = a;
                size[a] += size[b];
                count--;
                return true;
            }
        }

        int Find(int v) {
            if (v == parent[v]) return v;
            return parent[v] = Find(parent[v]);
        }   // path compression
    };


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        DSU uf{N};
        for (auto e : edges)
            if (!uf.Union(e[0]-1, e[1]-1))
                return e;
        return vector<int>();
    }
};
