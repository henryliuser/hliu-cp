class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int N = nums.size();
        vector<int> pre(N+1);
        vector<int> mods(k);
        mods[0]++;  // don't forget this. always gets me.
        int mx = 0;
        for (int z = 0; z < N; ++z) {
            pre[z+1] = (pre[z] + nums[z]%k) % k;
            pre[z+1] = (pre[z+1] + k) % k;
            ans += mods[pre[z+1]]++;
        }
        return ans;

        // for (int z = 0; z < k; ++z) {
        //     auto a = mods[z];
        //     if (a < 2) continue;
        //     // ans += fact[a] / (2ULL * fact[a-2]);
        //     ans += a*(a-1) / 2;
        // }

    }
};
