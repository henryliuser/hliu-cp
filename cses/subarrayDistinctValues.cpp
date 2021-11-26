#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int &x : A) cin >> x;

    ll i = 0, ans = 0;
    map<int, int> curr;
    for (int j = 0; j < N; ++j) {
        ++curr[A[j]];
        while (curr.size() > K)
            if (--curr[A[i++]] == 0)
                curr.erase(A[i-1]);
        ans += j-i+1;
    }
    cout << ans << "\n";

}
