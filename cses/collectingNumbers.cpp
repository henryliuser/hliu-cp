#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 1;
    int n; cin >> n;
    int st = 1;
    vector<int> A(n);
    cin >> A[0];
    for (int i = 1; i < n; ++i) {
        cin >> A[i];
        if (A[i] < A[i-1])
            ans = max(ans, ++st);
        else
            st = 1;
    }

    cout << ans << endl;
}
