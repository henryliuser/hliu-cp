#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b)
        swap(b, a %= b);
    return a;
}

vector<int> factorize(int n)
{
    int i;
    vector<int> factors;
    for (i = 1; i * i < n; i++) {
        if (n % i == 0)
            factors.push_back(i);
    }
    if (i - (n / i) == 1) --i;
    for (; i >= 1; i--) {
        if (n % i == 0)
            factors.push_back(n/i);
    }
    return factors;
}

int solve() {
    int ans = 0;
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    sort(begin(A), end(A));
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i)
        if (++cnt[A[i]] >= n/2) return -1;

    for (int t = 0; t <= n/2; ++t) {
        cnt.clear();
        int req = n/2-1;
        for (int i = t+1; i < n; ++i) {
            int diff = A[i] - A[t];
            if (diff == 0) --req;
            auto factors = factorize(diff);
            for (int f : factors) {
                if (++cnt[f] >= req)
                    ans = max(ans, f);
            }

        }
    }

    return ans;
}

int main() {
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";
}
