using ll = long long;

class Solution {
public:
    ll check(ll g, vector<int> &nums1, vector<int> &nums2) {
        ll res = 0;
        for (int n : nums1) {
            if (n > 0) {
                auto it = upper_bound(begin(nums2), end(nums2), floor(g * 1.0 / n));
                res += it - begin(nums2);
            }
            if (n < 0) {
                auto it = lower_bound(begin(nums2), end(nums2), ceil(g * 1.0 / n));
                res += end(nums2) - it;
            }
            if (n == 0 && g >= 0)
                res += nums2.size();
        }
        return res;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll lo = -1e10, hi = 1e10;
        while (lo < hi) {
            ll mid = lo + (hi-lo) / 2;
            ll c = check(mid, nums1, nums2);
            if (c < k) lo = mid+1;
            else hi = mid;
        }
        return lo;
    }
};
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
