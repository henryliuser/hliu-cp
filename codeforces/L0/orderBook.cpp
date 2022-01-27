// https://codeforces.com/problemset/problem/572/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define s second
#define f first

int main() {
    map<ll, ll> buy, sell;
    int N, S; cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        char d; cin >> d;
        ll p, q; cin >> p >> q;
        if (d == 'B') buy[p] += q;
        if (d == 'S') sell[p] += q;
    }
    vector<array<ll, 2>> a,b;
    for (int i = 0; i < S; ++i) {
        if (sell.empty()) break;
        auto it = begin(sell);
        a.push_back( {it->f, it->s} );
        sell.erase(it);
    }
    for (int i = 0; i < S; ++i) {
        if (buy.empty()) break;
        auto it = prev(end(buy));
        b.push_back( {it->f, it->s} );
        buy.erase(it);
    }
    reverse(begin(a), end(a));
    for (auto &x : a) printf("S %lld %lld\n", x[0], x[1]);
    for (auto &x : b) printf("B %lld %lld\n", x[0], x[1]);
}
