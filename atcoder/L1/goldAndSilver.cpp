#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    bool gold = true;
    double amt = 1.0;
    vector<int> ans(n), A(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        A[i] = x;
        if (i == 0) continue;
        if (gold) {
            if (x < A[i-1]) {
                gold = false;
                ans[i-1] = 1;
                amt *= A[i-1];
                if (i == n-1) {
                    ans[i] = 1;
                    amt /= x;
                }
            }
        }
        else {
            if (x > A[i-1]) {
                gold = true;
                ans[i-1] = 1;
                amt /= A[i-1];
            }
            else if (i == n-1) {
                ans[i] = 1;
                amt /= x;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);



}
