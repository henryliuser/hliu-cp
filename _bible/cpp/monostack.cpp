#define top(s) s.top()
struct Monostack {
    int N;
    vector<int> &A, loop;
    Monostack(vector<int> &a)
        : A(a), N(a.size()), loop(N) { iota(all(loop),0); }
    inline void rev() { if (loop[0] == 0) reverse( all(loop) ); }
    inline void fwd() { if (loop[0] != 0) reverse( all(loop) ); }
    template <class Functor>
    inline void go(vector<int> &L, Functor cmp, bool reverse) {
        if (reverse) rev(); else fwd();
        stack<int> s;
        for (int i : loop) {
            while ( !s.empty() && cmp(A[i], A[top(s)]) ) {
                L[top(s)] = i+1;
                s.pop();
            }
            s.push(i);
        }
    }
};
