class Solution {
public:
    void rotate(vector<int>& A, int k) {
        int N = A.size();
        k %= N;
        reverse(A.begin(), A.begin()+N-k);
        reverse(A.begin()+N-k, A.end());
        reverse(A.begin(), A.end());
    }
};
