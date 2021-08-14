#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("cowcode.in", "r", stdin);
    // freopen("cowcode.out", "w", stdout);
    string s; cin >> s;
    long long N; cin >> N;
    --N;  // 0-indexed
    int M = s.size();
    int rots = (N / M) % M;
    int idx = (N+1) % M;
    vector<char> s2(M);
    for (int z = 0; z < M; ++z)
        s2[z] = s[(z + rots) % M];
    printf("%d %d\n", rots, idx);
    for (auto xdx : s2) cout << xdx; cout << endl;
    cout << s2[idx] << endl;

}

// abcdef
// fabcde
// efabcd
// defabc
// cdefab
// bcdefa
//
// abcdef
