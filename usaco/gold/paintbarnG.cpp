#include <bits/stdc++.h>
using namespace std;

int N, K;
int dp[201][201]{};
int grid[201][201]{};
int cd1[4], cd2[4];

void update(int r1, int c1, int r2, int c2) {
    for (int r = r1; r <= r2; ++r)
        for (int c = c1; c <= c2; ++c)
            grid[r][c] = K;
}

int maxHistogram(int r, vector<int>& heights) {
    int ans = 0;
    stack<int> stn, stp;
    vector<int> nse(N, -1), pse(N, -1);
    for (int i = 0; i < N; ++i) {
        int x = heights[i];
        int y = heights[N-i-1];
        while (!stn.empty() && x < heights[stn.top()]) {
            int p = stn.top();
            nse[p] = i;
            stn.pop();
        }
        while (!stp.empty() && y < heights[stp.top()]) {
            int q = stp.top();
            pse[q] = N-i-1;
            stp.pop();
        }
        stn.push(i);
        stp.push(N-i-1);
    }
    for (int i = 0; i < N; ++i) {
        int h = heights[i];
        int next = nse[i]-1;
        int prev = pse[i]+1;
        if (next == -2) next = N-1;
        int area = h * (next-prev+1);
        if (area > ans) {
            ans = area;
            cd1[0] = r+h-1, cd1[1] = max(0,prev-1);
            cd1[2] = r+h-1, cd1[3] = min(N-1, next+1);
        }
    }
    return ans;
}

int maxRectangle() {
    int ans = 0;
    vector<vector<int>> dp2(201, vector<int>(200));
    for (int i = 1; i <= 200; ++i) {
        for (int j = 0; j < 200; ++j) {
            if (grid[i][j] == K-1)
                dp2[i][j] = 1 + dp2[i-1][j];
        }
    }
    for (int i = 1; i <= 200; ++i) {
        int h = maxHistogram(i-1, dp2[i]);
        if (h > ans) {
            ans = h;
            swap(cd1, cd2);
        }
    }
    update(cd2[0], cd2[1], cd2[2], cd2[3]);
    return ans;
}

int main() {
    // freopen("paintbarn.in", "r", stdin);
    // freopen("paintbarn.out", "w", stdout);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ++grid[x1][y1];
        --grid[x1][y2];
        --grid[x2][y1];
        ++grid[x2][y2];
    }
    for (int i = 0; i < 201; ++i)
        for (int j = 0; j < 201; ++j)
            dp[i+1][j+1] = grid[i][j] + dp[i][j+1];

    int curr = 0;
    for (int i = 0; i < 200; ++i)
        for (int j = 0; j < 200; ++j) {
            curr += dp[i+1][j+1];
            grid[i][j] = curr;
        }

    for (auto pm1 : grid) {
        for (auto pm2 : pm1) cout << pm2 << " ";
        cout << endl;
    }
    cout << maxRectangle() + maxRectangle() << endl;

}
