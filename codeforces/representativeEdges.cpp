#include <bits/stdc++.h>
using namespace std;
const double EPS = 0.000001;

bool cmp(double a, double b) {
    return abs(b-a) < EPS;
}

int solve() {
    int ans = INT_MAX;
    int N; cin >> N;
    vector<double> A(N);
    for (auto &x : A) cin >> x;
    if (N <= 2) return 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            // (i,j) determines interval
            int curr = 0;
            double df = A[j] - A[i];
            double dx = df / (j-i);
            for (int k = 0; k < N; ++k) {
                double v = A[i] + dx * (k-i);
                if (!cmp(A[k], v))
                    ++curr;
            }
            ans = min(ans, curr);
        }
    }
    return ans;

}

int main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << "\n";
}

// bool good(vector<int> &A) {
//     int N = A.size();
//     for (int i = 0; i < N; ++i) {
//         int sum = A[i];
//         for (int j = i+1; j < N; ++j) {
//             sum += A[j];
//             int rep = A[i] + A[j];
//             int len = j-i+1;
//             if (sum*2 != rep*len)
//                 return false;
//         }
//     }
//     return true;
// }
