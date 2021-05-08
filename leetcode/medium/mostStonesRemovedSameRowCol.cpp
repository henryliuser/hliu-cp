class Solution {
public:

    struct DSU {
        int count = 0;
        unordered_map<int, int> parent, size;
        void Add(int a) {
            if (parent.count(a)) return;
            parent[a] = a;
            size[a] = 1;
            count++;
        }
        bool Union(int a, int b) {
            Add(a), Add(b);
            a = Find(a), b = Find(b);
            if (a == b) return false;
            if (size[a] < size[b]) swap(a,b);
            parent[b] = a;
            size[a] += size[b];
            size[b] += size[a];
            count--;
            return true;
        }
        int Find(int a) {
            if (a == parent[a]) return a;
            return parent[a] = Find(parent[a]);
        }
    };

    int removeStones(vector<vector<int>>& stones) {
        DSU uf;
        for (auto& s : stones)
            uf.Union(s[0], -s[1]-1);
        return stones.size() - uf.count;
    }
};
