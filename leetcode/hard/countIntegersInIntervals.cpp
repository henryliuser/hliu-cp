// https://leetcode.com/contest/weekly-contest-293/problems/count-integers-in-intervals/
// just implementation
using ll = long long;
class CountIntervals {
public:
    using iv = pair<ll,ll>;
    ll cnt = 0;
    set<iv> ivals;
    CountIntervals() {

    }
    template <class IT>
    pair<IT,bool> mergeLeft(IT it) {
        auto [L,R] = *it;
        if (it == begin(ivals)) return {it,1};
        auto left = prev(it);
        auto [x,y] = *left;
        if (x <= L && L <= y) {
            ivals.erase(it);
            iv q = { x, max(R, y) };
            cnt -= y-x+1;
            ivals.erase(left);
            return {ivals.insert(q).first,0};
        }
        return {it,1};
    }
    template <class IT>
    pair<IT,bool> mergeRight(IT it) {
        auto [L,R] = *it;
        if (it == prev(end(ivals))) return {it,1};
        auto right = next(it);
        auto [x,y] = *right;
        if (L <= x && x <= R) {
            ivals.erase(it);
            iv q = { L, max(R, y) };
            cnt -= y-x+1;
            ivals.erase(right);
            return {ivals.insert(q).first,0};
        }
        return {it,1};
    }
    void add(int L, int R) {
        auto [it, p] = ivals.insert( {L,R} );
        if (!p) return;
        while (1) {
            auto [itr, stop] = mergeLeft(it);
            it = itr;
            if (stop) break;
        }
        while (1) {
            auto [itr, stop] = mergeRight(it);
            it = itr;
            if (stop) break;
        }
        cnt += (it->second - it->first + 1);
    }

    int count() {
        return cnt;
    }
};
