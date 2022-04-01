struct BIT {
    int N;
    vector<ll> bit;
    BIT(int n) : N(n), bit(n+1) {}
    BIT(vector<ll> &a) : BIT(a.size()) {
        for (int i = 0; i < N; ++i)
            update(i, a[i]);
    }
    void update(int i, ll val) {
        for (++i; i <= N; i += i & -i)
            bit[i] += val;
    }
    ll query(int i) {
        ll res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
};
