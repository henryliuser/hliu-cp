#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void init() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
}

int main() {
    init();
    int N; cin >> N;
    vector<int> A(N);
    for (int &x : A) cin >> x;

    int ans[2] = {INT_MAX, 0};
    int i = 0, j = N-1;
    while (i < j) {
        int gapL = A[i+1] - A[i];
        int gapR = A[j] - A[j-1];
        bool valL = uf.max(i+1) == ;
        bool valR

    }
}
