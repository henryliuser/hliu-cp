#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
string S;

int solve() {
    int M; cin >> M;
    char C; cin >> C;

    int i = 0, ans = 0;
    for (int j = 0; j < N; ++j) {
        if (S[j] != C) --M;
        while (M < 0)
            if (S[i++] != C)
                ++M;
        ans = max(ans, j-i+1);
    }
    return ans;
}

int main() {
    cin >> N >> S;
    int Q; cin >> Q;
    while (Q--)
        cout << solve() << "\n";
}
