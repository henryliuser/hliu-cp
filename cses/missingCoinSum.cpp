#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    ll curr = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] != 1) return curr + 1;
        curr += A[i];
    }
    return curr + 1;
}

int main() {
    cout << solve() << endl;
}
