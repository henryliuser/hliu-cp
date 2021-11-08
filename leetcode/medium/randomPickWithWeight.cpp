class Solution {
public:
    vector<int> &A, pre;
    Solution(vector<int>& w) : A(w) {
        int s = 0;
        for (int x : w) {
            pre.push_back(x + s);
            s += x;
        }
    }

    int pickIndex() {
        int r = rand() % pre.back() + 1;
        int idx = lower_bound(begin(pre), end(pre), r) - begin(pre);
        if (idx >= A.size()) --idx;
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
