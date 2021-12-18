// https://codeforces.com/problemset/problem/1512/G
// learned divisor sum sieve, apparently running in 1e7 log 1e7 works
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 10000000;
vector<ll> sumDiv(int N) {
    vector<ll> s(N+1);
    for (int i = 1; i <= N; ++i)
        for (int j = i; j <= N; j += i)
            s[j] += i;
    return s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    vector<ll> s = sumDiv(N);
    vector<ll> d(N+1, -1);
    for (int i = N; i > 0; --i) {
        if (s[i] > N) continue;
        d[ s[i] ] = i;
    }

    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        cout << d[x] << "\n";
    }
}
