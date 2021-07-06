class Solution {
public:
    // O(N) greedy. Similar to minimum taps to water garden.
    int jump(vector<int>& nums) {
        int ans = 0;
        int N = nums.size();
        int prev = 0, right = 0;
        for (int i = 0; i < N; ++i) {
            if (i > right) return -1;
            if (i > prev) {
                ans++;
                prev = right;
            }
            right = max(right, i+nums[i]);
        }
        return ans;
    }

    // Old BFS AC. Now is TLE.
    int jump(vector<int>& nums) {
        int N = nums.size();
        vector<bool> seen(N);
        queue<int> q;
        q.push(0);
        int ans = 0;

        while (int len = q.size()) {
            for (int a = 0; a < len; a++) {
                int p = q.front();
                q.pop();
                seen[p] = true;
                int jumps = nums[p];
                if (p == N-1) return ans;
                while (jumps) {
                    int newp = p + jumps--;
                    if (newp < N && !seen[newp])
                        q.push(newp);
                }
            }
            ans++;
        }
        return -1;
    }
};
