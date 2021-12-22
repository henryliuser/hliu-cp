#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
    int N; cin >> N;
    vector<int> A(N), seen(N);
    for (int &x : A)  cin >> x;

    int c = 0, ans = 0;
    while (A[c] != 2) {
        if (seen[c]) return -1;
        seen[c] = 1;
        c = A[c]-1;
        ++ans;
    }
    return ++ans;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << solve() << "\n";
}
