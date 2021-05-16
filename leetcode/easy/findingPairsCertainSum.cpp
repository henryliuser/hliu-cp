class FindSumPairs {
public:
    unordered_map<int, int> count2;
    vector<int>& n1, n2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : n1(nums1), n2(nums2) {
        for (int& n : nums2) count2[n]++;
    }

    void add(int index, int val) {
        count2[n2[index]];
        n2[index] += val;
        count2[n2[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for (int& n : n1)
            ans += count2[tot-n];
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
