#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M, Q;
    cin >> N >> M;
    vector<int> pre(M+1);
    vector<vector<char>> grid(N, vector<char>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
            if (!i || !j) continue;
            char W = grid[i][j-1];
            char N = grid[i-1][j];
            if (W == 'X' && N == 'X')
                pre[j+1] = 1;
        }
    }
    for (int j = 1; j <= M; ++j) pre[j] += pre[j-1];
    cin >> Q;
    while (Q--) {
        int a, b; cin >> a >> b;
        if (pre[b] - pre[a])
            printf("NO\n");
        else
            printf("YES\n");
    }

}
