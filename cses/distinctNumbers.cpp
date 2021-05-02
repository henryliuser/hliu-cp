#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {

    // int N; cin >> N;
    // vector<int> v(N);
    // int ans = 1;
    // for (int z = 0; z < N; z++) cin >> v[z];
    // sort(v.begin(), v.end());
    //
    // for (int z = 1; z < N; z++)
    //     ans += (v[z] != v[z-1]);
    //
    // cout << ans << endl;

    int N; cin >> N;
    set<int> s;
    while (N--) {
        int x; cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;

}
