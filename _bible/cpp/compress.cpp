// in-place coordinate compression
int compress(vector<int> &A, vector<int> &uq) {
    uq = A;
    sort( all(uq) );
    auto fin = unique( all(uq) );
    uq.resize( fin-begin(uq) );
    return uq.size();
}

template <class T>
struct Compress {
    int sz;
    vector<T> uq;
    Compress(vector<T> &A) { add(A); go(); }
    void add(vector<T> &A) {
        uq.reserve( uq.size() + A.size() );
        uq.insert( end(uq), all(A) );
    }
    int go() {
        sort( all(uq) );
        auto fin = unique( all(uq) );
        uq.resize( fin-begin(uq) );
        return sz = uq.size();
    }
    inline   T operator[](int i) { return uq[i]; }
    inline int operator()(int x) {
        return lower_bound( all(uq), x ) - begin(uq);
    }
};
