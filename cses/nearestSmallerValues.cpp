// https://cses.fi/problemset/task/1645
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    vector<int> st, ple(N), A(N);
    for (int &x : A) cin >> x;

    #define top st.back()
    for (int i = N-1; ~i; --i) {
        while (!st.empty() && A[i] < A[top]) {
            ple[top] = i+1;
            st.pop_back();
        }
        st.push_back(i);
    }

    for (int j : ple)
        cout << j << ' ';
}
