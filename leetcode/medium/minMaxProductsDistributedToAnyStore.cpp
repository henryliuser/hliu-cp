class Solution {
public:
    bool check(int n, int g, vector<int> &quant) {
        int m = quant.size();
        int c = 0, q = 0;
        for (int i = 0; i < n; ++i) {
            if (c >= m) break;
            q += g;
            if (q >= quant[c]) {
                ++c;
                q = 0;
            }
        }
        return c >= m;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 1, hi = (int)1e5 + 1;
        while (lo < hi) {
            int mid = lo + (hi-lo) / 2;
            if (check(n, mid, quantities))
                hi = mid;
            else
                lo = mid+1;
        }
        return lo;
    }
};
