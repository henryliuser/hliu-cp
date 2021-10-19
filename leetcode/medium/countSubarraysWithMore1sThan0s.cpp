// pretty fast BIT
class Solution {
public:
    static constexpr int MOD = 1e9+7;
    struct BIT {
        int N;
        vector<int> bit;
        BIT(int n) : N(n+1), bit(n+1) {}
        BIT(vector<int> &a) : BIT(a.size()) {
            for (int i = 0; i < N; ++i)
                update(i, a[i]);
        }
        void update(int i, int val) {
            for (++i; i <= N; i += i & (-i))
                bit[i] += val;
        }
        int query(int i) {
            int res = 0;
            for (++i; i > 0; i -= i & (-i))
                res += bit[i];
            return res;
        }
    };
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        int ans = 0;
        int N = nums.size();
        vector<int> pre(N+1);
        for (int i = 1; i <= N; ++i) {
            int x = nums[i-1];
            pre[i] = pre[i-1] + (x ? 1 : -1);
        }
        BIT bit(2*N+2);
        for (int i = 0; i <= N; ++i) {
            int q = bit.query(pre[i]+N-1);
            ans = (ans + q) % MOD;
            bit.update(pre[i]+N, 1);
        }
        return ans;

    }
};

// sometimes TLE n log n merge tree solution
class Solution {
public:
    const int MOD = 1e9+7;
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
                T[v].resize(tr-tl+1);
                auto &L = T[v*2], &R = T[v*2+1];
                merge(begin(L), end(L), begin(R), end(R), begin(T[v]));
            }
        }
        int query(int x, int L, int R) { return query(x, L, R, 1, 0, N-1); }
        int query(int x, int L, int R, int v, int tl, int tr) {
            if (L > R) return 0;
            if (tl == L && tr == R)
                return lower_bound(begin(T[v]), end(T[v]), x) - begin(T[v]);
            int mid = (tl + tr) / 2;
            int ql = query(x, L, min(R, mid), v*2, tl, mid);
            int qr = query(x, max(L, mid+1), R, v*2+1, mid+1, tr);
            return ql + qr;
        }
        MergeTree(int n, vector<int> &a)
            : N(n), A(a), T(4ul*n) { build(1, 0, N-1); }
    };
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        int ans = 0;
        int N = nums.size();
        vector<int> pre(N+1);
        for (int i = 1; i <= N; ++i) {
            int x = nums[i-1];
            pre[i] = pre[i-1] + (x ? 1 : -1);
        }
        MergeTree seg(N+1, pre);
        for (int i = 1; i <= N; ++i) {
            int q = seg.query(pre[i], 0, i-1);
            ans = (ans + q) % MOD;
        }
        return ans;

    }
};
