class Solution {
public:
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
