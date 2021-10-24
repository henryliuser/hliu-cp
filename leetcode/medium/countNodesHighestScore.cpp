using ll = long long;

class Solution {
public:

    static constexpr int MAXN = 1e5+1;
    // int dp1[MAXN][MAXN];
    // int dp2[MAXN];
    ll sz[MAXN]{};
    vector<vector<int>> graph;
    vector<vector<ll>> dp1;
    vector<ll> dp2;

    ll dfs(int u) {
        if (sz[u]) return sz[u];
        sz[u] = 1;
        for (int v : graph[u]) sz[u] += dfs(v);
        return sz[u];
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int N = parents.size();
        graph.resize(N);
        for (int i = 1; i < N; ++i)
            graph[parents[i]].push_back(i);
        dp1.assign(N, vector<ll>(2, -1));
        dp2.assign(N, -1);
        dfs(0);
        ll m = 0, ans = 0;
        for (int i = 0; i < N; ++i) {
            if (i != 0) dp2[i] = sz[0] - sz[i];
            for (int j = 0; j < graph[i].size(); ++j)
                dp1[i][j] = sz[graph[i][j]];
            ll q = abs( dp1[i][0] * dp1[i][1] * dp2[i] );
            if (q == m) ++ans;
            if (q > m) ans = 1, m = q;
        }
        return ans;
    }
};
