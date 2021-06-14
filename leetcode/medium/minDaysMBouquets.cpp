class Solution {
public:
    int N;
    bool check(vector<int>& b, int m, int k, int x) {
        int streak = 0;
        for (int z = 0; z < N; z++) {
            if (b[z] <= x) {
                if (++streak == k) {
                    m--;
                    streak = 0;
                }
            }
            else streak = 0;
        }
        return m <= 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        N = bloomDay.size();
        if (m * k > N) return -1;
        int lo = -1, hi = 1e9;
        while (lo <= hi) {
            int mid = lo + (hi-lo) / 2;
            if (check(bloomDay, m, k, mid)) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }
};
