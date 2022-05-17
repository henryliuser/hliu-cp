// https://leetcode.com/problems/count-integers-in-intervals/
// my editorial:
// https://leetcode.com/problems/count-integers-in-intervals/discuss/2045859/Very-Clean-C%2B%2B-std%3A%3Aset
using iv = pair<int,int>;
using IT = set<iv>::iterator;

struct CountIntervals {
    int cnt = 0;  // track the current count
    set<iv> ivals = { {-1,-1}, {INT_MAX,INT_MAX} };  // dummy values for edges

    template <class F>
    pair<IT,bool> merge(IT it, F dir) {         // -> {resulting IT, keep going?}
        auto [L,R] = *it;
        auto cmp = dir(it, 1);                  // dir is prev() or next()
        auto [x,y] = *cmp;
		bool intersectL = (L <= x && x <= R);
		bool intersectR = (x <= L && L <= y);
        if (intersectL || intersectR) {         // if `cmp` overlaps with `it`
            cnt -= y-x+1;                       // remove contribution from cmp
            ivals.erase(cmp);                   // erase both
            ivals.erase(it);
            iv q = { min(x, L), max(y, R) };    // merge into new, big interval
            return ivals.insert(q);             // insert merged interval
        }
        return {it, false};  // otherwise, return it and indicate stop merging
    }
    void add(int L, int R) {
        auto [it, go] = ivals.insert( {L,R} );
        if (!go) return;
        do {  tie(it,go) = merge(it, prev<IT>);  } while (go);  // merge left
        do {  tie(it,go) = merge(it, next<IT>);  } while (go);  // merge right
        tie(L, R) = *it;
        cnt += R-L+1;
    }
    int count() { return cnt; }
};
