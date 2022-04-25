struct Binomial {
    ll fact[MXN], finv[MXN], minv[MXN];
    Binomial() {
        fact[0] = minv[0] = finv[0] = 1;
        fact[1] = minv[1] = finv[1] = 1;
        for (int i = 2; i < MXN; ++i) {
            fact[i] = i * fact[i-1] % Q;
            minv[i] = Q - Q/i*minv[Q%i] % Q;
            finv[i] = finv[i-1] * minv[i] % Q;
        }
    }
    inline ll operator() (int n, int r) {
        ll v = fact[n] * finv[r] % Q;
        return v * finv[n-r] % Q;
    }
} nCr;
