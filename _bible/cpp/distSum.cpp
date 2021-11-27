#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DistSum {
    vector<ll> d[2], p[2];  // 0 left->right, 1 right->left
    DistSum(vector<ll> &a) {
        int n = a.size();
        for (int i : {0,1}) d[i].assign(n,0), p[i].assign(n,0);
        for (int i = 1; i < n; ++i) {
            d[0][i] = a[i] - a[i-1] + d[0][i-1];    // psum of dists
            p[0][i] = d[0][i] + p[0][i-1];  // psum of psum of dists
            d[1][n-i-1] = a[n-i] - a[n-i-1] + d[1][n-i];
            p[1][n-i-1] = d[1][n-i-1] + p[1][n-i];
        }
    }
    ll query(int src, int i) {
        int q = (src > i);
        ll diff = p[q][i] - p[q][src];
        ll cut = d[q][src];
        ll len = abs(src-i);
        return diff - cut * len;
    }
};

int main() {
    int n = 5;
    vector<ll> v = {0,0,3,4,5};
    DistSum ds(n, v);
    cout << ds.dist(0, 4) << "\n";
    cout << ds.dist(2, 0) << "\n";
    cout << ds.dist(2, 3) << "\n";
    cout << ds.dist(5, 4) << "\n";
    cout << ds.dist(3, 1) << "\n";
}
