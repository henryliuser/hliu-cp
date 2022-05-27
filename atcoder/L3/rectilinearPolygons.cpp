// https://atcoder.jp/contests/abc211/tasks/abc211_f
// incredible question. Recognize that a point is in a polygon
// when the number of intersections to the left (or in any direction) is ODD.
// using this fact, we can sort the queries and sweep across x to answer them.
// since we only care about intersections to the left, we also only care about vertical line segments
// we need to handle range +1/-1, and point queries, which we can accomplish with a BIT
// to determine the "sign" of a segment, we pre-process each shape, and toggle the segments
// one at a time to figure out what the correct sign is.
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

#define  ti(x) array<int, x>
#define all(x) begin(x), end(x)

struct BIT {
    int N;
    vector<int> bit;
    BIT(int n) : N(n), bit(n+1) {}
    BIT(vector<int> &a) : BIT(a.size()) {
        for (int i = 0; i < N; ++i)
            update(i, a[i]);
    }
    void update(int i, int val) {
        for (++i; i <= N; i += i & -i)
            bit[i] += val;
    }
    int query(int i) {
        int res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
};

int N, M, Q;
const int MXX = 1e5+5;
vector<ti(3)> A[MXX];  // vertical segments, indexed by x
vector<ti(2)> R[MXX];  // queries, indexed by x
BIT ft(MXX);           // keep track of count at each y

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> M;
        vector<ti(2)> P(M);
        for (auto &[x,y] : P) cin >> x >> y;
        vector<ti(3)> verts;
        for (int j = 0; j < M; ++j) {
            auto [x1, y1] = P[j];
            auto [x2, y2] = P[(j+1)%M];
            if (x1 == x2) {  // vertical line segment
                int yl = min(y1, y2);
                int yr = max(y1, y2);
                verts.push_back( {x1, yl, yr} );
            }
        }
        sort( all(verts) );  // by x
        for (auto [x,yl,yr] : verts) {        // use SegTree per shape
            bool reset = ft.query(yl);        // to compute the signs of each segment
            int f = (reset ? -1 : 1);         // it must always toggle back and forth
            ft.update(yl, f);
            ft.update(yr, -f);
            A[x].push_back( {yl, yr, f} );    // then stick it in here with the right sign for later
        }
    }

    cin >> Q;
    for (int x,y, q=0; q < Q; ++q) {
        cin >> x >> y;
        R[x].push_back( {y,q} );
    }

    vector<int> ans(Q);
    for (int x = 0; x < MXX; ++x) {     // sweep x from 0 to 1e5
        for (auto [y1,y2,f] : A[x])     // loop on vertical line segments at this x
            ft.update(y1, f),           // range update according to f (either +1 / -1)
            ft.update(y2, -f);
        for (auto [y,q] : R[x])         // queries at this x, with y and query index q
            ans[q] = ft.query(y);       // point query at y
    }

    for (int x : ans)
        cout << x << '\n';
}
