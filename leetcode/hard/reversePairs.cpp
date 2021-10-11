using ll = long long;

class Solution {
public:
    struct MergeTree {
        unsigned long N;
        vector<int> &A;
        vector<vector<ll>> T;
        void build(ll v, ll tl, ll tr) {
            if (tl == tr) T[v] = {A[tl]};
            else {
                ll mid = (tl + tr) / 2;
                build(v*2, tl, mid);
                build(v*2+1, mid+1, tr);
                T[v].resize(tr-tl+1);
                auto &L = T[v*2], &R = T[v*2+1];
                merge(begin(L), end(L), begin(R), end(R), begin(T[v]));
            }
        }
        ll query(ll x, ll L, ll R) { return query(x, L, R, 1, 0, N-1); }
        ll query(ll x, ll L, ll R, ll v, ll tl, ll tr) {
            if (L > R) return 0;
            if (L == tl && R == tr)
                return end(T[v]) - upper_bound(begin(T[v]), end(T[v]), 2*x);
            ll mid = (tl + tr) / 2;
            ll ql = query(x, L, min(R, mid), v*2, tl, mid);
            ll qr = query(x, max(L, mid+1), R, v*2+1, mid+1, tr);
            return ql + qr;
        }
        MergeTree(unsigned long n, vector<int> &a)
                : N{n}, A{a}, T{4*n, vector<ll>()} { build(1, 0, N-1); }

    };

    int reversePairs(vector<int>& nums) {
        long long ans = 0;
        unsigned long n = nums.size();
        MergeTree seg(n, nums);
        for (ll i = 1; i < n; ++i)
            ans += seg.query(nums[i], 0, i-1);

        return ans;
    }
};
