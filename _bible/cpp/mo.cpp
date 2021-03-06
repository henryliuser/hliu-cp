struct Mo {
    // static const int B = 500;   // block size
    static const int K = 21;    // hilbert order power, 2^K

    int L=1, R=0;
    vector<ll> &A;
    // int cnt[MXN] = {};
    // ll cur = 0;
    inline void del(ll x) {

    }
    inline void add(ll x) {

    }
    inline const ll get() {

    }
    static ll hilbert(int x, int y, int pow, int rotate) {
        if (pow == 0) return 0;
        int hpow = 1 << (pow-1);
        int seg = (x<hpow) ? ( (y<hpow)?0:3 ) : ( (y<hpow)?1:2 );
        seg = (seg + rotate) & 3;
        const int rotateDelta[4] = {3, 0, 0, 1};
        int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
        int nrot = (rotate + rotateDelta[seg]) & 3;
        ll subSquareSize = 1ll << (2*pow - 2);
        ll ans = seg * subSquareSize;
        ll add = hilbert(nx, ny, pow-1, nrot);
        ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
        return ans;
    }
    struct Query {
        ll ord;
        int l, r, i;
        void calc() { ord = hilbert(l, r, K, 0); }
        friend bool operator<(const Query& a, const Query& b) {
            return a.ord < b.ord;
        }
    };
    template <class T>
    void process(vector<Query> &qry, vector<T> &ans) {
        sort( all(qry) );
        for (Query &q : qry) {
            while (L > q.l) add( A[--L] );
            while (R < q.r) add( A[++R] );
            while (R > q.r) del( A[R--] );
            while (L < q.l) del( A[L++] );
            ans[q.i] = get();
        }
    }
    Mo(vector<ll> &a) : A(a) { }
};
