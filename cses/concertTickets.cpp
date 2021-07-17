#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, M; cin >> N >> M;
    multiset<int, greater<int>> price;
    while (N--) {
        int p; cin >> p;
        price.insert(p);
    }
    while (M--) {
        int c, res; cin >> c;
        auto it = price.lower_bound(c);
        if (it == price.end()) res = -1;
        else {
            res = *it;
            price.erase(it);
        }
        cout << res << endl;
    }

}
