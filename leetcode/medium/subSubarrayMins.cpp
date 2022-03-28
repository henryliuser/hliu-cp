// https://leetcode.com/problems/sum-of-subarray-minimums/
// monostack solution. refer to .py version for dp
class Solution {
public:
    using ll = long long;
    const int Q = 1e9 + 7;
    template <class Range, class Vec>
    void monostack(Vec &v, Vec &A, Range loop, bool geq) {
        stack<int> s;
        #define top (s.top())
        for (int i : loop) {
            while (s.size() && A[i]-geq < A[top]) {
                v[top] = i;
                s.pop();
            }
            s.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& A) {
        int N = A.size();
        vector<int> nsl(N,-1), nsr(N,N), r(N);
        iota(begin(r), end(r), 0);  // views::iota() is only c++20
        monostack(nsr, A, r, 0);
        reverse(begin(r), end(r));
        monostack(nsl, A, r, 1);

        ll ans = 0;
        for (int i = 0; i < N; ++i) {
            ll l = i - nsl[i];
            ll r = nsr[i] - i;
            ll x = (l*r * A[i]) % Q;
            ans = (ans + x) % Q;
        }
        return ans;


    }
};
