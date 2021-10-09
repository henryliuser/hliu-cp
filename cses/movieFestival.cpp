#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define f first
#define s second

int dp[20001];
int main() {
    int n; cin >> n;
    vector<pii> movies(n);
    for (int i = 0; i < n; ++i)
        cin >> movies[i].s >> movies[i].f;

    sort(begin(movies), end(movies));
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        pii& m = movies[i];
        int j = movies.lower_bound({m.s, -1}) - movies.begin();
        if (movies[j].f > m.s) --j;
        if (j >= 0) dp[i] += dp[j];
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n-1] << endl;

}
