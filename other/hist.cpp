#include <bits/stdc++.h>
using namespace std;
int M, N;
int maxAreaHistogram(vector<int>& heights) {
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
        int next = nse[i]-1;
        int prev = pse[i]+1;
        if (next == -2) next = N-1;
        int area = heights[i] * (next-prev+1);
        ans = max(ans, area);
    }
    return ans;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int ans = 0;
    M = matrix.size();
    N = matrix[0].size();
    vector<vector<int>> dp(M+1, vector<int>(N));
    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j < N; ++j) {
            char c = matrix[i-1][j];
            if (c == '1') dp[i][j] = 1 + dp[i-1][j];
            if (c == '0') dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= M; ++i) {
        ans = max( ans, maxAreaHistogram(dp[i]) );
    }
    return ans;
}

int main() {
    vector<vector<char>> mtx =
        {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
        };
    cout << maximalRectangle(mtx) << endl;

}
