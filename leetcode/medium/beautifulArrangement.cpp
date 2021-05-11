class Solution {
public:

    int N;
    void dfs(int x, int i, vector<bool>& seen, int& ans) {
        if ((i % x != 0) && (x % i != 0)) return;
        seen[x] = true;
        if (i == N) { ans++; seen[x] = false; return; }
        for (int z = 1; z <= N; z++)
            if (!seen[z])
                dfs(z, i+1, seen, ans);
        seen[x] = false;
    }

    int countArrangement(int n) {
        int ans = 0; N = n;
        vector<bool> seen(n+1);
        vector<int> path;
        for (int z = 1; z <= N; z++)
            dfs(z, 1, seen, ans);
        return ans;

    }
};
