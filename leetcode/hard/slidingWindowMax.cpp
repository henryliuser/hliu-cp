// O(N) mono deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int N = nums.size();
        for (int i = 0; i < k; ++i) {
            int x = nums[i];
            while (!dq.empty() && x > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for (int i = k; i < N; ++i) {
            int x = nums[i];
            if (dq.front() <= i-k) dq.pop_front();
            while (!dq.empty() && x > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

// O(N log N), pretty slow, using rbtree
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int N = nums.size();
        multiset<int> window;
        vector<int> ans;
        for (int i = 0; i < k; ++i)
            window.insert(nums[i]);
        ans.push_back(*window.rbegin());
        for (int i = k; i < N; ++i) {
            window.erase(window.find(nums[i-k]));
            window.insert(nums[i]);
            ans.push_back(*window.rbegin());
        }
        return ans;
    }
};
