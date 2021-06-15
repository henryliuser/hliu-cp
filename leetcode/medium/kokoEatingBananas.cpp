class Solution {
public:

    bool check(vector<int>& piles, int guess, int h) {
        int hrs = 0;
        for (int p : piles)
            hrs += ceil(p*1.0 / guess);
        return hrs <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int N = piles.size();
        int lo = 1, hi = 1e9;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            if (!check(piles, mid, h)) lo = mid+1;
            else hi = mid;
        }
        return lo;
    }
};
