class Solution {
public:

    int check(vector<int>& arr, int x) {
        int sum = 0;
        for (int& a : arr) {
            sum += min(a, x);
        }
        return sum;
    }

    int findBestValue(vector<int>& arr, int target) {
        int mx = -1;
        for (int& x : arr) mx = max(mx, x);
        int lo = 1, hi = mx;
        while (lo < hi) {
            int mid = lo + (hi-lo) / 2;
            int s = check(arr, mid);
            if (s >= target) hi = mid;
            else lo = mid+1;
        }
        int edgeL = abs(target-check(arr, lo-1));
        int L = abs(target-check(arr, lo));
        return (edgeL <= L) ? lo-1 : lo;
    }
};
