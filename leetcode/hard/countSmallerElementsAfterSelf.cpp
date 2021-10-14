// n log n segtree solution
class Solution {
public:
    struct MergeTree {
        int N;
        vector<int> &A;
        vector<vector<int>> T;
        void build(int v, int tl, int tr) {
            if (tl == tr) T[v] = {A[tl]};
            else {
                int mid = (tl + tr) / 2;
                build(v*2, tl, mid);
                build(v*2+1, mid+1, tr);
                auto &L = T[v*2], &R = T[v*2+1];
                T[v].resize(tr-tl+1);
                merge(begin(L), end(L), begin(R), end(R), begin(T[v]));
            }
        }
        int query(int x, int L, int R) { return query(x, L, R, 1, 0, N-1); }
        int query(int x, int L, int R, int v, int tl, int tr) {
            if (L > R) return 0;
            if (L == tl && R == tr)
                return lower_bound(begin(T[v]), end(T[v]), x) - begin(T[v]);
            int mid = (tl + tr) / 2;
            int ql = query(x, L, min(R, mid), v*2, tl, mid);
            int qr = query(x, max(L, mid+1), R, v*2+1, mid+1, tr);
            return ql + qr;
        }
        MergeTree(int n, vector<int> &a)
            : N(n), A(a), T(4ul*n, vector<int>()) { build(1, 0, n-1); }
    };

    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N);
        MergeTree seg(N, nums);
        for (int i = 0; i < N; ++i)
            ans[i] = seg.query(nums[i], i+1, N-1);
        return ans;

    }
};
