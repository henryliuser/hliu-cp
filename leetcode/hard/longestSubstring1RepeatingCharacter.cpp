// https://leetcode.com/problems/longest-substring-of-one-repeating-character/
class Solution {
public:
    using iv = array<int, 3>;
    // each interval will track [L, R, char]

    set<iv> ivals;  // intervals
    map<int,int> lens;  // length frequencies

    void cnt(int l) {
        // cnt(x)  adds a length x
        // cnt(-x) removes a length x
        int m = (l<0) ? -1 : 1;
        l = abs(l);
        if ( (lens[l] += m) <= 0 )
            lens.erase(l);
    }
    void add(iv t) {  // add new interval
        ivals.insert(t);
        cnt(t[1] - t[0] + 1);
    }
    void del(iv t) {  // erase existing interval
        ivals.erase(t);
        cnt( -(t[1]-t[0]+1) );
    }

    inline set<iv>::iterator split(int i, iv m, char ch) {
        // split the interval containing index i
        // into (up to 3) new intervals
        // return the iterator to the new interval containing i
        del(m);
        if (m[0] < i)
            add( {m[0], i-1, m[2]} );
        if (m[1] > i)
            add( {i+1, m[1], m[2]} );
        cnt(1);
        auto res = ivals.insert( {i, i, ch} );
        return res.first;   // returns the iterator of the inserted interval
    }

    template<class IT>
    void merge(IT it) {  // merge `it` with neighboring intervals
        iv m = *it;
        iv l = *prev(it);
        iv r = *next(it);

        del(m);
        int nl = m[0], nr = m[1];  // bounds of new interval

        if (l[2] == m[2])  // merge with left
            del(l),
            nl = l[0];

        if (m[2] == r[2])  // merge with right
            del(r),
            nr = r[1];

        add( {nl, nr, m[2]} );
    }

    void upd(int i, char ch) {  // process a query
        auto it = ivals.lower_bound( {i,i,0} );
        iv m = *it;
        if (m[0] > i) m = *(--it);  // take previous
        if (ch == m[2]) return;

        // here, m is the interval that contains i
        it = split(i, m, ch);
        merge(it);
    }

    vector<int> longestRepeating(string S, string qc, vector<int>& qi) {
        int N = S.size();
        int Q = qc.size();
        S = "?" + S + "?";  // add some dummy characters to eliminate edge cases

        int st = 1;
        char prev = S[1];
        add( {0,  0,  0} );  // some dummy intervals to eliminate edge cases
        add( {N+1,N+1,0} );  // significantly easier implementation this way
        for (int i = 2; i <= N+1; ++i) {
            if (S[i] == prev) continue;
            add( {st, i-1, prev} );
            prev = S[i];
            st = i;
        }

        vector<int> ans(Q);
        for (int i = 0; i < Q; ++i) {
            upd( qi[i]+1, qc[i] );
            ans[i] = lens.rbegin()->first;  // take the max length
        }
        return ans;
    }
};
