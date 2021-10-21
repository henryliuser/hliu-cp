#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int M, N;
vector<string> spots, plain;

int BX = 3;
int MOD = 1e9+7;
unordered_map<char, int> mp({
    {'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}
});

ll modPow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void rabinKarp(string& s, int m, vector<unordered_set<ull>>& hashes)
{
    ull t = 0;
    ull d = 1 << BX;
    ull h = modPow(2, BX*m-BX, MOD);
    for (int i = 0; i < m; ++i) {
        t = (d * t + mp[s[i]]) % MOD;
    }
    hashes[0].insert(t);
    for (int i = m; i < M; ++i) {
        t = (d * (t - mp[s[i-m]] * h) + mp[s[i]]) % MOD;
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
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
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
