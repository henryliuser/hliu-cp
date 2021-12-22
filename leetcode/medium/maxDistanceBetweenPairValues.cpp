class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        // chad O(N) two pointers :(
        int i = 0, j = 0, ans = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) ans = max(ans, j++ - i);
            else i++;
        }
        return ans;

        // O(N log N) binary search
        int ans = 0;
        int N = nums1.size(), M = nums2.size();
        for (int i = 0; i < N; i++) {
            int val = nums1[i];
            int L = i, R = M-1;
            bool fr = false;
            while (L <= R) {
                int mid = L + (R-L) /2;
                int val2 = nums2[mid];
                if (val2 > val) L = mid+1;
                else if (val2 < val) R = mid-1;
                else {
                    while (mid+1 < M && nums2[mid+1] == val) mid++;
                    L = mid; fr = true;
                    break;
                }
            }
            if (!fr) L -= 1;
            ans = max(ans, L-i);

        }
        return ans;
    }
};
