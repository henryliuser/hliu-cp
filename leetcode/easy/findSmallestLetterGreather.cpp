class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // auto it = upper_bound(letters.begin(), letters.end(), target);
        // return (it == letters.end()) ? letters[0] : *it;
        int N = letters.size();
        int lo = 0, hi = N;
        while (lo < hi) {
            int mid = lo + (hi-lo) / 2;
            if (letters[mid] > target) {
                hi = mid;
            }
            else lo = mid+1;
        }
        return (hi == N) ? letters[0] : letters[lo];
    }
};
