// https://leetcode.com/contest/weekly-contest-290/problems/number-of-flowers-in-full-bloom/
// easy kill with mergeSortTree or sweep line
using ll = long long;
struct MergeTree {
    int N;
    vector<ll> &A;
    vector<vector<ll>> T;
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
    ll query(ll x, int L, int R) { return query(x, L, R, 1, 0, N-1); }
    ll query(ll x, int al, int ar, int v, int tl, int tr) {
        if (tr < al || ar < tl) return 0;
        if (al <= tl && tr <= ar)
            return end(T[v]) - lower_bound(begin(T[v]), end(T[v]), x);
        int mid = (tl + tr) / 2;
        ll ql = query(x, al, ar, v*2, tl, mid);
        ll qr = query(x, al, ar, v*2+1, mid+1, tr);
        return ql + qr;
    }
    MergeTree(int n, vector<ll> &v)
        : N(n), A(v), T(4ul*n) { build(1, 0, N-1); }
};


class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int N = flowers.size();
        sort(begin(flowers), end(flowers));

        vector<ll> A(N), B(N);
        for (int i = 0; i < N; ++i)
            A[i] = flowers[i][0],
            B[i] = flowers[i][1];

        MergeTree seg(N, B);
        int M = persons.size();
        vector<int> ans(M, 0);

        for (int i = 0; i < M; ++i) {
            ll p = persons[i];
            int j = upper_bound(begin(A), end(A), p) - begin(A) - 1;
            if (j < 0) continue;
            ans[i] = seg.query(p,0,j);
        }
        return ans;
    }
};
