#include <bits/stdc++.h>
using namespace std;
int ans = INT_MAX;
int X, Y, K, M;
void dfs(int i, int b1, int b2) {
    ans = min(ans, abs(b1+b2-M));
    if (i >= K) return;
    dfs(i+1, X, b2);
    dfs(i+1, b1, Y);
    dfs(i+1, 0, b2);
    dfs(i+1, b1, 0);
    int d1 = X - b1;
    int d2 = Y - b2;
    int m21 = min(d1, b2);
    int m12 = min(d2, b1);
    dfs(i+1, b1+m21, b2-m21);
    dfs(i+1, b1-m12, b2+m12);
}

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    cin >> X >> Y >> K >> M;
    dfs(0, 0, 0);
    cout << ans << endl;
}
