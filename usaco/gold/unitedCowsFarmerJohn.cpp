#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll ans = 0;
    int N; cin >> N;
    vector<int> cows(N);
    for (int i = 0; i < N; ++i)
        cin >> cows[i];
    unordered_map<int, int> next;
    next[cows[N-1]] = N-1;
    vector<int> suf(N+1);
    for (int i = N-2; i >= 0; --i) {
        int x = cows[i];
        suf[i] = suf[i+1];
        // printf("%d %d\n", i, x);
        if (next.count(x)) {
            ans += next[x] - i - 1 - (suf[i] - suf[next[x]]);
            next[x] = i;
            ++suf[i];
            continue;
        }
        ans += next.size();
        next[x] = i;
        // printf("%d\n", ans);
    }
    cout << ans << endl;


}
