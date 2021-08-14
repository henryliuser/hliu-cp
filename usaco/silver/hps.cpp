#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int N; cin >> N;
    vector<char> hps(N);
    vector<int> h(N+1), p(N+1), s(N+1);
    for (int z = 0; z < N; ++z) {
        cin >> hps[z];
        h[z+1] = h[z] + (hps[z] == 'H');
        p[z+1] = p[z] + (hps[z] == 'P');
        s[z+1] = s[z] + (hps[z] == 'S');
    }
    int ans = 0;
    for (int z = 1; z <= N; ++z) {
        int left = max({ h[z], p[z], s[z] });
        int right = max({ h[N]-h[z], p[N]-p[z], s[N]-s[z] });
        ans = max(ans, left+right);
    }
    cout << ans << endl;

}
