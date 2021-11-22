#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll N, K;
vector<ll> A;

bool check(ll g) {
    ll res = 0, curr = 0;
    for (ll x : A) {
        if (x > g) return 0;
        curr += x;
        if (curr >= g) {
            ++res;
            if (curr == g) curr = 0;
            else curr = x;
        }
    }
    res += !!curr;
    return res <= K;
}

int main() {
    cin >> N >> K; A.resize(N);
    ll mx = 0, sum = 0;
    for (ll &x : A) {
        cin >> x;
        mx = max(mx, x);
        sum += x;
    }

    ll lo = mx, hi = sum;
    while (lo < hi) {
        ll mid = lo + (hi-lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";

}
