// efficient, easy, intuitive, better, 2 pointers
class Solution {
public:
    int threeSumClosest(vector<int>& A, int target) {
        int N = A.size();
        int ans = A[0] + A[1] + A[2];
        sort(begin(A), end(A));
        for (int k = 0; k < N; ++k) {
            int i = k+1, j = N-1;
            while (i < j) {
                int sum = A[i] + A[j] + A[k];
                if (abs(sum-target) < abs(ans-target))
                    ans = sum;
                if (sum < target) ++i;
                if (sum > target) --j;
                if (sum == target) return target;
            }
        }
        return ans;
    }
};

// easy intuitive multiset
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        multiset<int> s;
        int N = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < N; ++i)
            s.insert(nums[i]);

        for (int i = 0; i < N; ++i) {
            s.erase(s.find(nums[i]));
            for (int j = i+1; j < N; ++j) {
                s.erase(s.find(nums[j]));
                int t = target - nums[i] - nums[j];
                auto it = s.lower_bound(t);
                if (it == end(s)) it = prev(it);
                int sum = nums[i] + nums[j] + *it;
                if (abs(sum-target) < abs(ans-target))
                    ans = sum;
                if (it != begin(s)) {
                    sum -= *it - *prev(it);
                    if (abs(sum-target) < abs(ans-target))
                        ans = sum;
                }
                s.insert(nums[j]);
            }
            s.insert(nums[i]);
        }
        return ans;
    }
};
