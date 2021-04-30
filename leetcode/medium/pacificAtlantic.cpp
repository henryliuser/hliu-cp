class Solution {
public:
    int dp[200][200];
    int n, m;
    bool bfs(int c, int r, const vector<vector<int>>& h,
             int n, int m) {
        bool pc = false, at = false;
        queue<pair<int,int>> q;
        vector<vector<bool>> seen(n, vector<bool>(m));
        q.push(make_pair(c, r));
        printf("%d, %d\n", r, c);
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int col = p.first, row = p.second;
            if (seen[row][col]) continue;
            else seen[row][col] = true;
            int val = h[row][col], &oc = dp[row][col];
            printf("%d %d | v: %d, dp: %d, pc: %d, at: %d\n", row, col, val, oc, pc, at);
            for (int z = 0; z < n; z++) {
                    for (int a = 0; a < m; a++)
                        cout << dp[z][a] << " ";
                    cout << endl;
                }
            if (oc == 1) pc = true;
            if (oc == 2) at = true;
            if (oc == 3) pc = true, at = true;
            if (col - 1 >= 0 && h[row][col-1] <= val) {
                int aa = dp[row][col-1];
                if (aa == 1) pc = true;
                if (aa == 2) at = true;
                if (aa == 3) pc = true, at = true;
            }

            if (pc) oc = 1;
            if (at) oc = 2;
            if (pc && at) { oc = 3; return true; }


            if (col + 1 <  m && h[row][col+1] <= val)
                q.push(make_pair(col+1, row));
            // if (row - 1 >= 0 && h[row-1][col] <= val)
            //     q.push(make_pair(col, row-1));
            if (row + 1 <  n && h[row+1][col] <= val)
                q.push(make_pair(col, row+1));
            cout << q.empty() << endl;
        }
        return false;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // int dp[n][m]; // 0:none, 1:Pacific, 2:Atlantic, 3:Both
        n = heights.size(), m = heights[0].size();
        vector<vector<int>> ans;
        // initialize dp
        for (int z = 0; z < n; z++)
            for (int a = 0; a < m; a++)
                dp[z][a] = 0;
        for (int r = 0; r < n; r++) {
            dp[r][0]   = 1;
            dp[r][m-1] = 2;
        }
        for (int c = 0; c < m; c++) {
            dp[0][c]   = 1;
            dp[n-1][c] = 2;
        }
        dp[n-1][0] = 3;
        dp[0][m-1] = 3;

        // stupid bfs idk
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (bfs(c, r, heights, n, m)) ans.push_back( {r, c} );
            }
        }
        return ans;

    }
};
