// https://codeforces.com/gym/103640/problem/J
// only N if you encounter points along the border in ABAB fashion
// sort such that you process them in clockwise or counter-clockwise order
// use a stack
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
using pi = array<int,3>;
#define all(x) begin(x), end(x)

int W, H, N;
const ll ORD = 1e9+2;

inline bool onBorder(int x, int y) {
    return (!x || !y || x == W || y == H);
}

// impose ccw ordering
inline ll key(int x, int y) {
    if (y == 0) return x;
    if (x == W) return ORD + y;
    if (y == H) return 3*ORD - x;
    if (x == 0) return 5*ORD - y;
}

inline bool cmp(pi a, pi b) {
    return key(a[0], a[1]) < key(b[0], b[1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<pi> A;
    cin >> W >> H >> N;
    for (int x,y,a,b, i=0; i < N; ++i) {
        cin >> x >> y >> a >> b;
        if (onBorder(x,y) && onBorder(a,b))
            A.push_back( {x,y,i} ),
            A.push_back( {a,b,i} );
    }
    sort( all(A), cmp );

    stack<int> st;
    for (pi p : A) {
        int i = p[2];
        if (!st.empty() && st.top() == i) {
            st.pop();
            continue;
        }
        st.push(i);
    }
    cout << (st.empty() ? 'Y' : 'N') << '\n';
}
