#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> cows;
vector<int> dpR, dpL;

int main() {
    // freopen("angry.in", "r", stdin);
    // freopen("angry.out", "w", stdout);
    cin >> N; cows.resize(N);
    dpL.assign(N, 0);
    dpR.assign(N, 0);
    for (int z = 0; z < N; ++z)
        cin >> cows[z];
    sort(cows.begin(), cows.end());
    int mxL = 0, mxR = N-1;  // critical cows
    for (int z = 1; z <= N; ++z) {
        int x = cows[z];
        int lastL = cows[z-1];
        if (x > cows[mxL]+dpL[mxL]+1) {  // new critical cow
            mxL = z;
            dpL[z] = max(x-lastL, dpL[z-1]+1);
        }
        else dpL[z] = dpL[mxL] + 1;

        int y = cows[N-z-1];
        int lastR = cows[N-z];
        if (y < cows[mxR]-dpR[mxR]-1) {
            mxR = N-z-1;
            dpR[N-z-1] = max(lastR-y, dpR[N-z] + 1);
        }
        else dpR[N-z-1] = dpR[mxR] + 1;
    }
//    for (auto d : dpL) cout << d << " "; cout << "\n";
//    for (auto d : dpR) cout << d << " "; cout << "\n";
    double ans = INT_MAX;
    for (int i = 0; i < N-1; ++i) {
        double a = cows[i];
        double b = cows[i+1];
        double x = (a+b) / 2.0 - a;
        double m = max(dpL[i], dpR[i+1]) + 1.0;
        ans = min(ans, max(x, m));
    }
    printf("%.2f\n", ans);

}
