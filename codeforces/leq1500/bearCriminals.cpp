#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, a;
    cin >> n >> a; a--;
    vector<int> v(n);
    for (int z = 0; z < n; z++)
        cin >> v[z];

    int ans = v[a] == 1;
    int i = a-1, j = a+1;
    while (i >= 0 && j < n) {
        if (v[i] && v[j]) ans += 2;
        i--; j++;
    }
    while (i >= 0) ans += v[i--];
    while (j <  n) ans += v[j++];
    cout << ans << endl;


}
