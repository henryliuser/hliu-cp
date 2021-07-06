class Solution {
public:
    // O(N) greedy
    int videoStitching(vector<vector<int>>& clips, int time) {
        int N = clips.size();
        vector<int> lengths(time+1);
        for (int z = 0; z < N; ++z) {
            int start = clips[z][0];
            int end = clips[z][1];
            if (start > time) continue;
            lengths[start] = max(lengths[start], end);
        }
        int ans = 0;
        int prev = 0, right = 0;
        for (int z = 0; z <= time; ++z) {
            if (z > right) return -1;
            if (z > prev) {
                ans++;
                prev = right;
            }
            right = max(right, lengths[z]);
        }
        return ans;
    }

    // O(100N) DP
    int videoStitching(vector<vector<int>>& clips, int time) {
        int N = clips.size();
        sort(clips.begin(), clips.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });
        vector<int> dp(time+1, N+1);
        dp[0] = 0;
        for (int z = 0; z < N; ++z) {
            int s = clips[z][0];
            int e = clips[z][1];
            if (s < 0 || s > time || e < 0) continue;
            for (int a = s; a <= min(e, time); ++a)
                dp[a] = min(dp[a], dp[s]+1);
        }
        if (dp[time] > N) return -1;
        return dp[time];

    }
};
