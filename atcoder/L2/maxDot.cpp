// https://atcoder.jp/contests/arc128/tasks/arc128_c
// really instructive math-ish problem.
// first consider wihthout M constraint.
// do greedy weighted suffix sum, find best sfx(j) / j;
// then 2 cases on M
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
        for (int j = 1; j <= N-i; ++j)
            sfx[j] = sfx[j-1] + A[N-i-j];

        int m = 1;
        for (int j = 2; j <= N-i; ++j) {
            double s = sfx[j] / j;
            if (s > sfx[m] / m)
                m = j;
        }
        double r = 1.0*S / m;
        if (r > M) {
            for (int j = 0; j < m; ++j)
                B[bc--] = M;
            i += m-1;
            S -= m*M;
        }
        else {
            for (int j = 0; j < m; ++j)
                B[bc--] = r;
            break;
        }
    }
    return dot();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(10);
    cin >> N >> M >> S;
    A.resize(N); B.resize(N);
    for (ll &x : A) cin >> x;

    cout << solve() << "\n";
}
