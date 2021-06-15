class Solution {
public:

    bool check(vector<int>& weights, int guess, int d) {
        int days = 1;
        int curr = 0;
        for (int w : weights) {
            if (w > guess) return false;
            curr += w;
            if (curr > guess) {
                curr = w;
                days++;
                if (days > d) return false;
            }
        }
        return days <= d;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int N = weights.size();
        int s = 0;
        for (int w : weights) s += w;
        int lo = 1, hi = s;
        while (lo < hi) {
            int mid = lo + (hi-lo) / 2;
            if (check(weights, mid, days))
                hi = mid;
            else lo = mid+1;
        }
        return lo;
    }
};
