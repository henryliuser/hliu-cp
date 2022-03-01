// https://codeforces.com/problemset/problem/1630/C
// process the leftmost and rightmost occurrence for each element
// we're going minimize the number of 0 color's left
// if you have a whole contained segment:
// 1xx2x3xx2xx3xxx1 -> ans += 2, delete mid, left with 11
// if you have an interlocking segment length S:
// 1x2x3x4x1x2x3x4 -> ans += |S|+1, optimal is left with 12344 or 11234
// if you have non-contained solo numbers:
// 1xxxx2xx1xx25 -> ans += 1, (for the 5.)
// do a sweepline
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

}
