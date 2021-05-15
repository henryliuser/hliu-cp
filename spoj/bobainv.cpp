#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> nums(N+1), dp(N+1);
    for (int z = 1; z <= N; z++)
        cin >> nums[z];
    for (int i = 1; i <= N; i++)
        for (int j = i+1; j <= N; j++)
            dp[j] += (nums[i] < nums[j]);

    int M; cin >> M;
    for (int z = 0; z < M; z++) {
        int a, b; cin >> a >> b;
        cout << dp[b] - dp[a];

    }



}
