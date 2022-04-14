struct SparseTable {
    int N, K;
    vector<vector<ll>> T;
    int msb(int x) {  // log2(x) in O(1)
        union { double a; int b[2]; };
        a = x;
        return (b[1] >> 20) - 1023;
    }
    SparseTable (vector<ll> &A) {
        N = A.size();
        K = msb(N) + 1;
        T.assign(N, vector<ll>(K+1));
        for (int i = 0; i < N; ++i)
            T[i][0] = A[i];
        for (int j = 1; j <= K; ++j)
            for (int i = 0; i <= N-(1<<j); i++)
                T[i][j] = gcd(T[i][j-1], T[i+(1<<(j-1))][j-1]);  // adjust
    }
    ll query(int l, int r) {
        ll res = 0;  // adjust
        for (int i = K; ~i; --i)
            if (l+(1<<i)-1 <= r) {
                res = gcd(res, T[l][i]);  // adjust
                l += (1<<i);
            }
        return res;
    }
};
