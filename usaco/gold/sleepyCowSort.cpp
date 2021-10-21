#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int N;
    vector<int> bit;
    void update(int i, int val) {
        for (++i; i <= N; i += i & (-i))
            bit[i] += val;
    }
    int query(int L, int R) { return query(R) - query(L-1); }
    int query(int i) {
        int res = 0;
        for (++i; i > 0; i -= i & (-i))
            res += bit[i];
        return res;
    }
    BIT(int n) : N(n+1), bit(n+1) {}
};

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    int i = n-2;
    while (i >= 0 && A[i] < A[i+1]) --i; ++i;
    cout << i << endl;
    BIT ft(n+1);
    for (int j = i; j < n; ++j)
        ft.update(A[j], 1);
    int c = i-1;
    for (int j = 0; j < i; ++j) {
        int q = ft.query(A[j]);
        printf("%d", q + c--);
        printf((j == i-1) ? "\n" : " ");
        ft.update(A[j], 1);
    }

}
