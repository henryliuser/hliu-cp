// https://codeforces.com/contest/1644/problem/E
// condense into segments
// suffix sum of path
// first segment unchangeable, call it `init`
// (i,j) = seg[0]  # coords after initial segment
// totalArea = init + (N-i)(N-j)
// keep track of `lost`
// for all i:
//   t = type(seg[i])
//   lost += sfx[t][i] * len(seg[i+1])
//         (restricted * len of next seg)
// return totalArea - lost
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {

}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
