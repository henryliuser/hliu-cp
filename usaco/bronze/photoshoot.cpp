// reversing a prefix flips all the parities
// split into alternating segments of pairs
// 4 cases
// OEO  -> m
// EOE  -> m-1
// OEOE -> m-1
// EOEO -> m
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

int N;
string S;

int main() {
    int M = 0;  // num segments
    cin >> N >> S;
    int last = -1;
    for (int x=-1, i=0; i < N; i+=2, x=-1) {
        string c(1, S[i]);
        c += S[i+1];
        if (c == "HG") x = 0;
        if (c == "GH") x = 1;
        if (x == -1) continue;  // discard all GG's and HH's, they
        if (x != last)          // contribute equally to answer
            ++M, last = x;
    }
    int sub = (last == 0);
    cout << M - sub << '\n';
}
