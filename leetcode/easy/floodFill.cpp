class Solution {
public:

    int N, M;
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(int r, int c, int color,
             vector<vector<int>>& image,
             vector<vector<bool>>& seen)
    {
        seen[r][c] = true;
        int ogColor = image[r][c];
        image[r][c] = color;
        for (auto d : dirs) {
            int x = r + d.first, y = c + d.second;
            if (x >= 0 && x < N && y >= 0 && y < M)
                if (!seen[x][y] && image[x][y] == ogColor) {
                    dfs(x, y, color, image, seen);
                }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        N = image.size(), M = image[1].size();
        vector<vector<bool>> seen(N, vector<bool>(M));
        dfs(sr, sc, newColor, image, seen);
        return image;
    }
};
