class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> xAxis, yAxis;
    DetectSquares() {}

    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        ++xAxis[x][y];
        ++yAxis[y][x];
    }

    int count(vector<int> point) {
        int ans = 0;
        int x = point[0];
        int y = point[1];
        auto& mpY = xAxis[x];
        auto& mpX = yAxis[y];
        for (auto it : mpX) {
            int xx = it.first, cnt = it.second;
            if (xx == x) continue;
            int dim = xx - x;
            int above = mpY[y+dim] * cnt * xAxis[xx][y+dim];
            int below = mpY[y-dim] * cnt * xAxis[xx][y-dim];
            ans += above + below;
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
