#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    int N; string s;
    cin >> N >> s;
    stack<int> st;
    vector<int> left(N), right(N);
    for (int j = N-1; j >= 0; --j) {
        if (s[j] == '1') {
            right[j] = -1;
            int x = j;
            while (!st.empty()) {
                right[++x] = j;
                st.pop();
            }
            continue;
        }
        st.push(0);
    }
    int z = -1;
    while (!st.empty()) {
        st.pop();
        right[++z] = -1;
    }
    for (int j = 0; j < N; ++j) {
        if (s[j] == '1') {
            left[j] = -1;
            int x = j;
            while (!st.empty()) {
                left[--x] = j;
                st.pop();
            }
            continue;
        }
        st.push(0);
    }
    z = N - 1;
    while (!st.empty()) {
        st.pop();
        left[z--] = -1;
    }
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        if (s[i] == '1') continue;
        int l = abs(left[i] - i);
        int r = abs(right[i] - i);
        if (left[i] == -1) ans += r;
        else if (right[i] == -1) ans += l;
        else ans += min(l, r);
    }
    return ans;
}

int main() {
    int T; cin >> T;
    for (int i = 1; i <= T; ++i)
        cout << "Case #" << i << ": " << solve() << endl;
}
