#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int j; cin >> j;
        if (mp.count(x-j)) {
            printf("%d %d\n", mp[x-j]+1, i+1);
            return 0;
        }
        mp[j] = i;
    }
    printf("IMPOSSIBLE\n");
}
