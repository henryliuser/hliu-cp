// https://leetcode.com/problems/boats-to-save-people
class Solution {
public:
    // 2p 72 ms
    int numRescueBoats(vector<int>& A, int limit) {
        int ans = 0;
        int N = A.size();
        sort(begin(A), end(A));
        int i = 0, j = N-1;
        while (i < j) {
            int s = A[i] + A[j];
            if (s <= limit) ++i;
            ++ans;
            --j;
        }
        return ans + (i==j);
    }
    // rbtree 188 ms
    // int numRescueBoats(vector<int>& A, int limit) {
    //     int ans = 0;
    //     multiset<int> ms(begin(A), end(A));
    //     while (!ms.empty()) {
    //         auto itA = begin(ms);
    //         int x = *itA;
    //         ms.erase(itA);
    //         auto itB = ms.upper_bound(limit-x);
    //         if (itB != begin(ms))
    //             ms.erase(--itB);
    //         ++ans;
    //     }
    //     return ans;
    // }
};
