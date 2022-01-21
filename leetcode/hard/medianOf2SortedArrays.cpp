// https://leetcode.com/problems/median-of-two-sorted-arrays/
// binary search on partition in A.
// use the size of the halves to find partition of B.
// check if valid
class Solution {
public:
    const int INF = 1e8;
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) swap(A, B);
        int N = A.size();
        int M = B.size();
        int T = N+M;
        int S = T / 2;

        int lo = -1, hi = N-1;
        while (lo <= hi) {
            int al = -INF, ar = INF;
            int bl = -INF, br = INF;
            int i = lo + (hi-lo) / 2;
            int j = S - i - 2;
            if (i>=0)  al = A[i];
            if (i+1<N) ar = A[i+1];
            if (j>=0)  bl = B[j];
            if (j+1<M) br = B[j+1];
            // (al>br && bl>ar) case cannot happen
            if      (al > br) hi = i-1;
            else if (bl > ar) lo = i+1;
            else {
                if (T % 2) return 1.0*min(ar, br);
                int x = max(al, bl);
                int y = min(ar, br);
                return (x+y) / 2.0;
            }
        }
        return -1;
    }
};
