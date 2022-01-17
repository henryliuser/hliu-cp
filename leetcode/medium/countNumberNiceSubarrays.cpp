// https://leetcode.com/problems/count-number-of-nice-subarrays/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int N = nums.size();
        unordered_map<int, int> mp;

        mp[0] = 1;
        int cur = 0, ans = 0;
        for (int i = 0; i < N; ++i) {
            cur += (nums[i] % 2);
            ans += mp[cur-k];
            ++mp[cur];
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int N = nums.size();
        int i = 0, f = -1;
        int cur = 0, ans = 0;
        deque<int> dq;
        for (int j = 0; j < N; ++j) {
            int y = nums[j] % 2;
            cur += y;
            if (y && f == -1) dq.push_back(j);
            while (cur > k) {
                y = nums[i] % 2;
                cur -= y;
                ++i;
                if (y) dq.pop_front();
            }
            if (cur == k)
                ans += dq.front()-i+1;
        }
        return ans;
    }
        // int N = nums.size();
        // int i = 0, ans = 0, last = 0;
        // deque<int> cur;
        // for (int j = 0; j < N; ++j) {
        //     if (nums[j] % 2) cur.push_back(j);
        //     while (cur.size() > k) {
        //         ans += cur.front() - last + 1;
        //         int x = nums[i];
        //         if (x % 2) cur.erase(i);
        //         ++i;
        //     }
        //     if (cur.size() == k)
        //         ans +=
        // }
        // return ans;
};
