class Solution {
public:
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
};
