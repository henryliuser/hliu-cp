class Solution {
public:
    struct DSU {
        int psz[1001];
        DSU() { memset(psz, -1, sizeof psz); }
        bool unite(int a, int b) {
            a = find(a), b = find(b);
            if (a == b) return false;
            if (psz[a] > psz[b]) swap(a, b);
            psz[a] += psz[b];
            psz[b] = a;
            return true;
        }
        int find(int a) {
            if (psz[a] < 0) return a;
            return psz[a] = find(psz[a]);
        }
    };

    DSU uf;
    vector<unordered_set<int>> block;

    bool valid(int u, int v, vector<vector<int>> &rest) {
        if (block[u].count(v)) return false;
        int x = uf.find(u), y = uf.find(v);
        for (auto &r : rest) {
            int a = r[0], b = r[1];
            a = uf.find(a), b = uf.find(b);
            if (x==a && y==b) return false;
            if (x==b && y==a) return false;
        }
        uf.unite(x, y);
        return true;
    }

    vector<bool> friendRequests(int n, vector<vector<int>>& rest, vector<vector<int>>& req) {
        block.resize(n);
        for (auto &r : rest)
            block[r[0]].insert(r[1]);
        int R = req.size();
        vector<bool> ans(R);
        for (int i = 0; i < R; ++i) {
            int u = req[i][0], v = req[i][1];
            ans[i] = valid(u, v, rest);
        }
        return ans;
    }
};
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
