#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int M, N;
vector<string> spots, plain;

int BX = 5;
ull MOD = (1ULL << 63) - 25;

ull modPow(ull x, ull y, ull q) {
    if (y == 0) return 1;
    auto p = modPow(x, y/2, q);
    if (y % 2 == 1) return (p*p*x) % q;
    return (p*p) % q;
}

void rabinKarp(string& s, int m, vector<unordered_set<ull>>& hashes)
{
    ull t = 0;
    ull d = 1 << BX;
    ull h = modPow(2, BX*m-BX, MOD);
    for (int i = 0; i < m; ++i)
        t = (d * t + s[i]-'a') % MOD;
    hashes[0].insert(t);
    for (int i = m; i < M; ++i) {
        t = (d * (t - (s[i-m]-'a') * h) + s[i]) % MOD;
        hashes[i-m+1].insert(t);
    }
}

bool check(int g) {
    vector<unordered_set<ull>> srk(M-g+1), prk(M-g+1);
    for (string& s : spots) rabinKarp(s, g, srk);
    for (string& p : plain) rabinKarp(p, g, prk);
    for (int i = 0; i < M-g+1; ++i) {
        bool found = false;  // compute (srk[i] & prk[i]) set intersection
        for (ull q : srk[i])
            if (prk[i].count(q)) {
                found = true; break;
            }
        if (!found) return true;  // set intersection is empty
    }
    return false;
}

int main() {
    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);
    cin >> N >> M;
    spots.resize(N); plain.resize(N);
    for (int z = 0; z < N; ++z) cin >> spots[z];
    for (int z = 0; z < N; ++z) cin >> plain[z];

    int lo = 0, hi = M;
    while (lo < hi) {
        int mid = lo + (hi-lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
}
