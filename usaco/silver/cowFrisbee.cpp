// http://usaco.org/index.php?page=viewproblem&cpid=1171
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int &x : A) cin >> x;

    // all neighbors are guaranteed to be good
    // count the pairs using mono-stack?
    // when 2 elements on the stack are adjacent it means
    // there's nothing else in between
    ll ans = 0;
    stack<int> st;
    for (int i = 0; i < N; ++i) {
        while (!st.empty() && A[i] > A[st.top()]) {
            int j = st.top();
            st.pop();
            if (i == j+1) continue; // avoid double counting this for later i guess
            ans += (i-j+1);
        }
        // at this point, elements can also be adjacent
        if (!st.empty() && st.top() != i-1)  // avoid double count
            ans += (i-st.top()+1);
        st.push(i);
    }
    ll neighbors = 2*N-2;  // get the ones we missed earlier
    ans += neighbors;
    cout << ans << '\n';
}
