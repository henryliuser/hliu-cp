// https://codeforces.com/problemset/problem/1641/D
// count valid pairs using map + PIE
// sort arrays by W and run 2 pointers
// interesting part from the middle 2 pointers --i, j++
// should use a trie to count subsets but managed to make this map pass
// once u find the baseline (i,j), you never consider higher j for same i
// so can decrement i until it works then increment j again
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")  // tle without this
#pragma GCC target ("avx2")  // slightly faster than sse4
using namespace std;
using dna = array<int, 5>;

#define d second
#define w first
#define all(x) (x).begin(), (x).end()

int N, M, S, C=0;
map<dna, int> cnt;
vector<pair<int,dna>> A;

inline int pie(dna &a, int add) {  // return number of valid pairs, before add
    int r[5] = {};
    for (int m = 1; m < S; ++m) {
        int pc = -1;
        dna c = {-1,-1,-1,-1,-1};
        for (int b = 0; b < M; ++b)
            if (m & (1<<b))
                c[++pc] = a[b];
        int &ct = cnt[c];
        r[pc] += ct;
        ct += add;
    }
    int inv = r[0] - r[1] + r[2] - r[3] + r[4];
    int res = C - inv;
    C += add;
    return res;
}

int solve() {
    cin >> N >> M;
    A.resize(N);
    S = 1 << M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 5; ++j) A[i].d[j] = 1e9+5;
        for (int j = 0; j < M; ++j)
            cin >> A[i].d[j];
        cin >> A[i].w;
        sort( all(A[i].d) );
    }
    sort( all(A) );

    int j = 0;
    while (j < N && pie(A[j].d,1) == 0) ++j;
    if (j >= N) return -1;
    pie(A[j].d, -1);

    int i = j;
    while ( pie(A[j].d, 0) != 0 )
        pie(A[--i].d, -1);

    int ans = A[i].w + A[j].w;
    for (j++; j < N && i > 0; ++j) {
        while (pie(A[j].d, 0) != 0) {
            pie(A[--i].d, -1);
            ans = min(ans, A[i].w + A[j].w);
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << solve() << '\n';
}
