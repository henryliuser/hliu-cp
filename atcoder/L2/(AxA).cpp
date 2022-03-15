// https://atcoder.jp/contests/abc242/tasks/abc242_e
// find the # valid <= "problem" palindrome
// case on the problem palindrome
// # valid is just number of different combinations for digits [0..(N-1)/2]
// interpret as base-26 number and compute the value of it in decimal
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;
const ll Q = 998244353;

int N;
string S;

void add(ll &a, ll b) { ((a+=b)>=Q)?a-=Q:0; }
void mul(ll &a, ll b) { a=a*b%Q; }

ll solve() {
    cin >> N >> S;
    string T = S;
    int i=0, j=N-1;
    while (i < j) T[j--] = T[i++];

    ll ans = 0;
    int lim = (N-1)/2;
    for (int z = 0; z <= lim; ++z) {
        mul(ans, 26);
        add(ans, S[z]-'A');
    }
    add(ans, 1);
    if (T > S) add(ans, Q-1);
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';
}
