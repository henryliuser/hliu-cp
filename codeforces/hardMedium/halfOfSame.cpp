#include <bits/stdc++.h>
using namespace std;

set<int> factorize(int n) {
    set<int> f;
    for (int x = 1; x*x <= n; ++x)
        if (n % x == 0) {
            f.insert(n / x);
            f.insert(x);
        }
    return f;
}

int solve() {
    int ans = 0;
    int n; cin >> n;
    vector<int> A(n);
    for (int &x : A) cin >> x;
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
            for (int f : factorize(diff))
                if (++cnt[f] >= req)
                    ans = max(ans, f);
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--)
        cout << solve() << "\n";
}
