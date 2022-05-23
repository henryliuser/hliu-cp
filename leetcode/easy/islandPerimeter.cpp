class Solution {
public:

    // good math
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0, repeat=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0; j<grid[i].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                        count ++;
                        if(i!=0 && grid[i-1][j] == 1) repeat++;
                        if(j!=0 && grid[i][j-1] == 1) repeat++;
                    }
                }
        }
        return 4*count-repeat*2;
    }

    // bad DFS
//     int N, M;
//     vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0,1}, {0,-1}};

//     void dfs(int r, int c, vector<vector<int>>& grid,
//              vector<vector<bool>>& seen, int& ans)
//     {
//         seen[r][c] = true;
//         int count = 4;
//         for (auto& d : dirs) {
//             int x = r + d.first, y = c + d.second;
//             if (x >= 0 && x < N && y >= 0 && y < M) {
//                 if (grid[x][y] == 1) {
//                     count--;
//                     if (!seen[x][y])
//                         dfs(x, y, grid, seen, ans);
//                 }
//             }
//         }
//         ans += count;
//     }

//     int islandPerimeter(vector<vector<int>>& grid) {
//         int ans = 0;
//         N = grid.size(), M = grid[0].size();
//         vector<vector<bool>> seen(N, vector<bool>(M));
//         for (int r = 0; r < N; r++) {
//             for (int c = 0; c < M; c++) {
//                 if (grid[r][c] == 1) {
//                     dfs(r, c, grid, seen, ans);
//                     break;
//                 }
//             }
//             if (ans != 0) break;
//         }
//         return ans;
//     }
};
