#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int N; cin >> N;
    vector<int> preMod(N);
    cin >> preMod[0];
    preMod[0] %= 7;
    for (int a = 1; a < N; a++) {
        cin >> preMod[a];
        preMod[a] += preMod[a-1];
        preMod[a] %= 7;
    }
    int ans = 0;
    for (int a = 0; a < 7; a++) {
        int first = -1, last = N;
        for (int z = 0; z < N; z++)
            if (preMod[z] == a) {
                first = z;
                break;
            }
        for (int z = N-1; z >= 0; z--)
            if (preMod[z] == a) {
                last = z;
                break;
            }
        if (first == -1) continue;
        ans = max(ans, last-first);
    }
    cout << ans << endl;

}

void badSolution() {   // barely runs in time (1870 ms)
    int N; cin >> N;
    vector<long long> pre(N+1);
    for (int z = 1; z <= N; z++) {
        cin >> pre[z];
        pre[z] += pre[z-1];
    }
    int ans = 0;
    try {
        for (int g = N; g > 0; g--)
            for (int a = 0; a < N-g; a++) {
                if ((pre[a+g] - pre[a]) % 7 == 0){
                    ans = g;
                    throw -1;
                }
            }

    }
    catch (...) {}

    cout << ans << endl;
}
