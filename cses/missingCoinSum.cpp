#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    sort(begin(A), end(A));
    int i = 0;
    ll curr = 0;
    while (i < n && A[i] - curr < 2)
        curr += A[i++];
    return curr+1;
}

int main() {
    cout << solve() << endl;
}
