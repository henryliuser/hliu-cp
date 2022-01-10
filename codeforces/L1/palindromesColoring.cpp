// https://codeforces.com/contest/1624/problem/D
// math moment
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define S second
#define F first

int N, K;
int j = 0, r = 0;
string S;
unordered_map<char, int> cnt;

bool check(int g) {
    if (g%2==0) return (2*j/g) >= K;
    else {
        int q = 2*j/(g-1);
        int p = min(q,r);
        int o = 2*j - (g-1)*p;
        p += o/g;
        return p >= K;
    }
}

ll solve() {
    cnt.clear();
    j = r = 0;
    cin >> N >> K >> S;
    for (char ch : S) ++cnt[ch];
    for (auto p : cnt) {
        j += p.S / 2;
        r += p.S % 2;
    }

    int lo = 1, hi = N;
    while (lo < hi) {
        int mid = lo + (hi-lo+1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        cout << solve() << "\n";
}
