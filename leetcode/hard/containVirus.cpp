class Solution {
public:

    int M, N;
    vector<vector<bool>> seen;
    int dirs[4][2] = {{1,0}, {-1,0}, {0, 1}, {0,-1}};
    vector<vector<vector<bool>>> wallMtx;

    queue<pair<int, int>> markQ, allQ;
    pair<int, int> dfs(vector<vector<int>>& inf, int r, int c) {
        if (seen[r][c]) return {0, 0};
        seen[r][c] = true;
        int willInfect = 0;
        int wall = 0;
        for (auto& d : dirs) {
            int x = r + d[0];
            int y = c + d[1];
            if (x >= 0 && x < M && y >= 0 && y < N) {
                if (inf[x][y] != 1) {
                    wall++;
                    if ()
                    wallQ.push({x,y});
                }
                if (inf[x][y] == 0) {
                    if (!seen[x][y]) {
                        willInfect++;
                        seen[x][y] = true;
                        markQ.push({x, y});
                        allQ.push({x, y});
                    }
                }
                if (inf[x][y] == 1) {
                    auto df = dfs(inf, x, y);
                    wall += df.first;
                    willInfect += df.second;
                }
            }
        }
        return {wall, willInfect};
    }

    int containVirus(vector<vector<int>>& isInfected) {
        cout << "++++++++++" << endl;
        M = isInfected.size();
        N = isInfected[0].size();
        wallMtx.assign(M, vector<vector<bool>>(N, vector<bool>(4)));
        // 0: left, 1: top, 2: right, 3: bot
        int walls = 0;
        int mx = -1;
        while (mx != 0) {
            printf("%d %d\n-----------\n", mx, walls);
            for (auto x : isInfected) {
                for ( auto y : x) printf("%3d ", y);
                cout << endl;
            } cout << endl;
            mx = 0;
            int mxW = 0;
            seen.assign(M, vector<bool>(N));
            for (int r = 0; r < M; r++) {
                for (int c = 0; c < N; c++) {
                    if (isInfected[r][c] == 1 && !seen[r][c]) {
                        auto wd = dfs(isInfected, r, c);
                        int w = wd.first, d = wd.second;
                        if (d > mx) {
                            mxW = w;
                            mx = d;
                        }
                        while (!markQ.empty()) {
                            auto p = markQ.front();
                            markQ.pop();
                            isInfected[p.first][p.second] = -d;
                        }
                    }
                }
            }
            walls += mxW;
            while (!allQ.empty()) {  // mark new infections
                auto p = allQ.front();
                allQ.pop();
                int r = p.first, c = p.second;
                int& i = isInfected[r][c];
                if (i < 0 && i != -mx)
                    i = 1;
                if (i == -mx) i = 0;
            }



            // for (int r = 0; r < M; r++) {  // mark new infections
            //     for (int c = 0; c < N; c++) {
            //         int& i = isInfected[r][c];
            //         if (i < 0 && i != -mx)
            //             i = 1;
            //     }
            // }
        }
        return walls;


    }
};
