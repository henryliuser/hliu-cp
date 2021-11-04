#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define f first
#define s second
const int INF = 1e9+1;
vector<vector<ll>> dp[2];
int cost(pii& a, pii &b) {
    int dx = a.f - b.f;
    int dy = a.s - b.s;
    return dx * dx + dy * dy;
}

int main() {
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    int H, G; cin >> H >> G;
    dp[0].assign(H+1, vector<ll>(G+1, INF));
    dp[1].assign(H+1, vector<ll>(G+1, INF));
    vector<pii> A(H+1), B(G+1);
    for (int i = 1; i <= H; ++i)
        cin >> A[i].f >> A[i].s;
    for (int i = 1; i <= G; ++i)
        cin >> B[i].f >> B[i].s;

    dp[0][H][G] = 0;
    ll nextH, nextG;
    for (int i = H-1; i >= 1; --i) {
        for (int j = G; j >= 0; --j) {
            for (int k = 1; k >= 0; --k) {
                if (k == 0) {
                    nextH = dp[0][i+1][j] + cost(A[i], A[i+1]);
                    if (i == H-1 && j != G) nextH = INF;
                    nextG = INF;
                    if (j != G) nextG = dp[1][i][j+1] + cost(A[i], B[j+1]);
                }
                if (k == 1) {
                    nextH = dp[0][i+1][j] + cost(B[j], A[i+1]);
                    nextG = INF;
                    if (j != G) nextG = dp[1][i][j+1] + cost(B[j], B[j+1]);
                }
                dp[k][i][j] = min(nextH, nextG);
            }
        }
    }

    cout << dp[0][1][0] << endl;


}
