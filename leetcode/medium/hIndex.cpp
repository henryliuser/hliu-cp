class Solution {
public:

    int N;
    int check(vector<int>& citations, int guess) {
        int alh = 0; // at least h
        bool met = false;
        for (int z = N-1; z >= 0; --z) {
            int c = citations[z];
            if (met) {
                if (c > guess) return 1; // doesn't work, exclude & go higher
                else return 0; // works, include & go higher
            }
            if (c >= guess) alh++;
            if (alh == guess) met = true;
        }
        if (met) return 0; // works, include & go higher
        return -1; // doesn't work, exclude & go lower
    }

    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        N = citations.size();
        int lo = 0, hi = N;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2 + 1;  // idk why this works
            int c = check(citations, mid);
            if (c <  0) hi = mid-1;
            if (c == 0) lo = mid;
            if (c >  0) lo = mid+1;
        }
        return lo;

    }
};
