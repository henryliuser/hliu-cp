class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int N = nums.size();
        deque<int> mono;
        vector<int> pre(N+1);
        for (int z = 1; z <= N; ++z)
            pre[z] = pre[z-1] + nums[z-1];

        int ans = N+1;
        for (int i = 0; i <= N; ++i) {
            int b = pre[i];
            while (!mono.empty() && pre[mono.back()] > b)
                mono.pop_back();
            while (!mono.empty() && pre[mono.front()] <= b - k) {
                ans = min(ans, i-mono.front());
                mono.pop_front();
            }
            mono.push_back(i);
        }
        return (ans == N+1) ? -1 : ans;
        
    }
};
