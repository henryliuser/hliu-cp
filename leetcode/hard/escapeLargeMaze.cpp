// # if # of blocks NOT limited to 200:
// # maintain running region
// # if (x,y) in seen
// #   region = list[idx[seen] : -1]
// #   check if src/target contained,
// # count number of regions containing src/target
// # if they match then true
// # 2 axis hits: axes become bounds
// sad that this convoluted mess wasn't the real solution lol
class Solution {
public:
    unordered_map<int, unordered_set<int>> obs;
    int dirs[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    bool bfs(int sx, int sy, int tx, int ty) {
        queue<pair<int, int>> q;
        q.push({sx, sy});
        unordered_map<int, unordered_set<int>> seen;
        int size = 0;
        while (!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            if (x == tx && y == ty) return true;
            if (size >= 19900) return true;
            if (seen[x].count(y)) continue;
            seen[x].insert(y);
            ++size;
            for (auto& d : dirs) {
                int r = x + d[0];
                int c = y + d[1];
                if (seen[r].count(c)) continue;
                if (r < 0 || r >= 1000000) continue;
                if (c < 0 || c >= 1000000) continue;
                if (obs[r].count(c)) continue;
                q.push({r, c});
            }
        }
        return false;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int sx = source[0], sy = source[1];
        int tx = target[0], ty = target[1];
        for (auto& b : blocked) obs[b[0]].insert(b[1]);
        return bfs(sx, sy, tx, ty) && bfs(tx, ty, sx, sy);
    }
};
