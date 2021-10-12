struct MergeTree {
    ll N;
    vector<ll> &A;
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
            return end(T[v]) - upper_bound(begin(T[v]), end(T[v]), x);
        ll mid = (tl + tr) / 2;
        ll ql = query(x, L, min(R, mid), v*2, tl, mid);
        ll qr = query(x, max(L, mid+1), R, v*2+1, mid+1, tr);
        return ql + qr;
    }
    MergeTree(ll n, vector<ll>& a)
        : N{n}, A{a}, T{4ul*n+1, vector<ll>()} { build(1, 0, n-1); }
};

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        multiset<pair<int, int>> ms;
        int N = obstacles.size();
        vector<int> dp(N,1), ans(N, 1);
        for (int i = 0; i < N; ++i) {
            int o = obstacles[i];
            if (!ms.empty()) {
                auto it = ms.upper_bound({o, i});
                if (it != begin(ms)) {
                    it = prev(it);
                    int j = it->second;
                    dp[i] += dp[j];
                }
            }
            ms.insert({o, i});
            ans[i] = dp[i];
        }
        return ans;
    }
};
