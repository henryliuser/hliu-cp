class Solution {
public:
    bool seen[30][30][64];
    int  dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int shortestPathAllKeys(vector<string>& grid) {
        memset(seen, 0, sizeof seen);
        int M = grid.size();
        int N = grid[0].size();
        queue<tuple<int, int, int>> q;
        unordered_map<char, int> bitPos;
        for (int r = 0; r < M; ++r)  // search for start and locks/keys
            for (int c = 0; c < N; ++c) {
                char ch = grid[r][c];
                if (ch == '.') continue;
                if (ch == '@') q.push({r, c, 0});
                else if (ch > 96 && ch < 123 && !bitPos.count(ch))
                    bitPos[ch] = bitPos.size();  // lower case and new
            }
        int ans = -1;
        int done = (1 << bitPos.size()) - 1;
        while (!q.empty()) {
            ++ans;
            int len = q.size();
            for (int z = 0; z < len; ++z) {
                auto [r, c, k] = q.front();
                q.pop();
                if (k == done) return ans;
                if (seen[r][c][k]) continue;
                seen[r][c][k] = true;
                for (auto& d : dirs) {
                    int x = r + d[0];
                    int y = c + d[1];
                    if (x < 0 || x >= M || y < 0 || y >= N)
                        continue;
                    char ch = grid[x][y];
                    if (ch == '#') continue;
                    if (seen[x][y][k]) continue;
                    if (ch == '.' || ch == '@')      // Empty
                        q.push({x, y, k});
                    else if (ch > 96 && ch < 123) {  // Key
                        int bp = bitPos[ch];
                        int key = 1 << bp;
                        if ((k | key) == done)
                            return ans+1;
                        q.push({x, y, k | key});
                    }
                    else if (ch > 64 && ch < 91) {   // Lock
                        int bp = bitPos[ch + 32];  // which key?
                        int qr = 1 << bp;    // bit query
                        if (qr == (k & qr))  // if we have the key
                            q.push({x, y, k});
                    }
                }
            }
        }
        return -1;
    }
};
