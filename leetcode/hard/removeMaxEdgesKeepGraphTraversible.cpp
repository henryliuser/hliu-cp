class Solution {
public:
    struct DSU {
        int count;
        vector<int> parent, size;
        vector<bool> seen;
        DSU(int N) : count(N), parent(N, -1), size(N, 1), seen(N) {};
        bool Union(int a, int b) {
            a = Find(a), b = Find(b);
            if (a == b) return false;
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            count--;
            return true;
        }
        int Find(int a) {
            if (parent[a] == -1) return a;
            return parent[a] = Find(parent[a]);
        }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
            return a[0] > b[0];
        });
        DSU alice{n}, bob{n};
        vector<vector<bool>> type(2, vector<bool>(n));
        int ans = 0;
        for (auto& e : edges) {
            int t = e[0], a = e[1]-1, b = e[2]-1;
            if (t == 3) {
                bool al = alice.Union(a, b);
                bool bo = bob.Union(a, b);
                ans += (!al || !bo);
                continue;
            }
            if (t == 1) {
                ans += !alice.Union(a,b);
            }
            if (t == 2) {
                ans += !bob.Union(a,b);
            }
        }
        if (alice.count > 1 || bob.count > 1) return -1;
        return ans;
    }
};
