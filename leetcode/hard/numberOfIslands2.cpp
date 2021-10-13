class Solution {
public:

    int dirs[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

    struct DSU {
        int count = 0;
        unordered_map<int, int> parent, size;
        void add(int a) {
            if (size.count(a)) return;
            parent[a] = -1;
            size[a] = 1;
            ++count;
        }
        bool unite(int a, int b) {
            a = find(a), b = find(b);
            if (a == b) return false;
            if (size[a] < size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
            --count;
            return true;
        }
        int find(int a) {
            if (parent[a] == -1) return a;
            return parent[a] = find(parent[a]);
        }
    };

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        DSU uf;
        int cnt = 0;
        int k = positions.size();
        vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            int x = positions[i][0];
            int y = positions[i][1];
            int idx = x * n + y;
            uf.add(idx);
            for (auto d : dirs) {
                int r = x + d[0];
                int c = y + d[1];
                if (r >= m || r < 0 || c >= n || c < 0)
                    continue;
                int j = r * n + c;
                if (uf.size.count(j))
                    uf.unite(idx, j);
            }
            ans[i] = uf.count;
        }
        return ans;
    }
};
