#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M, S;
vector<ll> A;
vector<double> B;

double dot() {
    double res = 0.0;
    for (int i = 0; i < N; ++i)
        res += B[i] * A[i];
    return res;
}

double solve() {
    int bc = N-1;
    for (int i = 0; i < N; ++i) {
        vector<double> sfx(N-i+1);
        for (int j = 1; j < N-i; ++j)
            sfx[j] = sfx[j-1] + A[N-i-j];

        int m = 1;
        for (int j = 2; j <= N-i; ++j) {
            double s = sfx[j] / j;
            if (s > sfx[m] / m)
                m = j;
        }
        double r = S / m;
        if (r > M) {
            for (int j = 0; j < m; ++j)
                B[bc-- - j] = M;
            i += m-1;
            S -= m*M;
        }
        else {
            for (int j = 0; j < m; ++j)
                B[bc--  -  j] = r;
            return dot();
        }
    }
    return dot();
}

int main() {
    cin >> N >> M >> S;
    A.resize(N); B.resize(N);
    for (ll &x : A) cin >> x;

    cout << solve() << "\n";
}
