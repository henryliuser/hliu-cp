#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
using ll = long long;

int N, M;
string S, A;
bool isSubseq(int i=0, int j=0) {

}
string alph = "abcde";
string solve() {
    int i=0, j=0;
    cin >> N >> M >> S >> A;
    if (N < M) return "-1";
    while (i < N && j < M) {
        if (S[i] == A[j]) ++j;
        if (S[i] == '?') {
            for (char c : alph)
                if (c != A[j]) {
                    S[i] = c;
                    break;
                }
        }
        ++i;
    }

    if (j == M) return "-1";
    return S;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        cout << solve() << '\n';
}
