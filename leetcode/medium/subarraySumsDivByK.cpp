class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int N = nums.size();
        vector<int> mods(k);
        mods[0] = 1;  // don't forget this.
        long long curr = 0;
        for (int z = 0; z < N; ++z) {
            curr = (curr + (nums[z]%k)) % k;
            curr = (curr+k)%k;
            ans += mods[curr]++;
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
