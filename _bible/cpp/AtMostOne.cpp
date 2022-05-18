struct Encoding {
    int z = 0;
    int vars = 0;
    TwoSAT *ts;
    vector<bool> aux;
    explicit Encoding(int n) : aux(3*n) {
        ts = new TwoSAT(3*n);
        for (int i = 0; i < n; ++i)
            take(i);
    }
    inline void take(int k) {
        if (aux[k]) return;
        aux[k] = true;
        ++vars;
    }
    inline void add(int i, bool f, int j, bool g) {
        ts->add_clause(i,f,j,g);
        take(i), take(j);
    }
    inline int mex() {
        while (aux[z] && z < aux.size()) ++z;
        take(z);
        return z;
    }
    inline bool satisfiable() const { return ts->satisfiable(); }
    ~Encoding() { delete ts; }
};

// recursive 2-product At Most One encoding by Jingchao Chen
// 2n + 4*sqrt(N) + O(N^(1/4))  clauses
// 2*sqrt(N) + O(N^(1/4))       auxiliary variables
void AMO(vector<int> &x, Encoding &enc) {
    int N = x.size();
    if (N <= 3) {
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                enc.add(x[i], false, x[j], false);
        return;
    }
    int p = ceil( sqrt(N) );
    int q = ceil( N*1.0/p );
    vector<int> u(p), v(q);
    for (int i = 0; i < p; ++i) u[i] = enc.mex();  // reserve new auxiliary variables
    for (int i = 0; i < q; ++i) v[i] = enc.mex();
    for (int i = 1; i <= p; ++i)
        for (int j = 1; j <= q; ++j) {
            int k = (i-1) * q + j - 1;
            if (k >= N) break;
            enc.add(x[k], false, u[i-1], true);
            enc.add(x[k], false, v[j-1], true);
        }
    AMO(u, enc);
    AMO(v, enc);
}
