// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/
// loop only on set bits, in practice much faster than O(N log A[i]), but
// worse case is slightly slower
class Solution {
public:
    int largestCombination(vector<int> &A) {
        int cnt[24] = {};
        for (int x : A)
            for (; x > 0; x ^= x & -x) {
                int c = __builtin_ctz(x);
                ++cnt[c];
            }
        return *max_element(cnt, cnt+24);
    }
};
