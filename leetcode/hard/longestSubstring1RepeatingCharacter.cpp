// https://leetcode.com/contest/weekly-contest-285/problems/longest-substring-of-one-repeating-character/
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using ti = array<int, 3>;

class Solution {
public:

    set<ti> ivals;
    map<int,int> lens;

    void cnt(int l) {
        int m = (l<0) ? -1 : 1;
        l = abs(l);
        if ( (lens[l] += m) <= 0 )
            lens.erase(l);
    }
    void add(ti t) {
        ivals.insert(t);
        cnt(t[1] - t[0] + 1);
    }
    void del(ti t) {
        ivals.erase(t);
        cnt(-(t[1]-t[0]+1));
    }

    inline set<ti>::iterator split(int i, ti m, char ch) {
        del(m);
        if (m[0] < i)
            add( {m[0], i-1, m[2]} );
        if (m[1] > i)
            add( {i+1, m[1], m[2]} );
        cnt(1);
        auto res = ivals.insert( {i, i, ch} );
        return res.first;
    }

    template<class IT>
    void merge(IT it) {
        auto m = *it;
        auto l = *prev(it);
        auto r = *next(it);

        char a = l[2], b = m[2], c = r[2];
        if (a == b && b == c) {
            del(l), del(m), del(r);
            add( {l[0], r[1], a} );
            return;
        }
        if (a == b) {
            del(l), del(m);
            add( {l[0], m[1], a} );
            return;
        }
        if (b == c) {
            del(m), del(r);
            add( {m[0], r[1], b} );
            return;
        }
    }

    void upd(int i, char ch) {
        auto it = ivals.lower_bound( {i,i,0} );
        if (it == end(ivals)) --it;
        auto m = *it;
        bool ok = (m[0] <= i && i <= m[1]);
        if (!ok) m = *(--it);
        if (ch == m[2]) return;

        it = split(i, m, ch);
        merge(it);
    }

    vector<int> longestRepeating(string S, string qc, vector<int>& qi) {
        int N = S.size();
        int M = qc.size();
        vector<int> ans(M);
        S = "?" + S + "?";

        int st = 1;
        char prev = S[1];
        ivals.insert( {0,  0,  0} );
        ivals.insert( {N+1,N+1,0} );
        for (int i = 2; i <= N+1; ++i) {
            if (S[i] == prev) continue;
            ivals.insert( {st, i-1, prev} );
            ++lens[i-st];
            prev = S[i];
            st = i;
        }

        for (int i = 0; i < M; ++i) {
            upd( qi[i]+1, qc[i] );
            ans[i] = lens.rbegin()->first;
        }
        return ans;
    }
};
